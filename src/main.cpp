#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

#include <protocol_version.h>
#include <base/world.h>

#include <base/robot.h>
#include <utils/geom.h>

int main()
{
  // Pre setup
  char protocol[64];
  int version;
  World world;

  scanf("%s %d", protocol, &version);
  if (strcmp(protocol, "ROBOIME_AI_PROTOCOL_VERSION") == 0 && version == PROTOCOL_VERSION)
    printf("COMPATIBLE %d\n", PROTOCOL_VERSION);
  else
    printf("NON_COMPATIBLE %d\n", PROTOCOL_VERSION);

  //setup
  world.load();

  while (true)
  {
    char ref_state;
    float ref_time_left;
    float timestamp;
    float ball_x, ball_y, ball_vx, ball_vy;
    int id_goalkeeper,
        num_robots,
        opponent_num_robots;

    std::vector<Robot> robots,
      opponent_robots;

#ifndef NDEBUG
    if (scanf(" %c %f", &ref_state, &ref_time_left) == EOF)
      break;
#else
    scanf(" %c %f", &ref_state, &ref_time_left);
#endif
    scanf(" %f", &timestamp);

    scanf("%f %f %f %f", &ball_x, &ball_y, &ball_vx, &ball_vy);
    scanf("%d %d", &id_goalkeeper, &num_robots);

    for (int i = 0; i < num_robots; i++)
    {
      int id;
      float x, y, w, vx, vy, vw;
      scanf("%d %f %f %f %f %f %f", &id, &x, &y, &w, &vx, &vy, &vw);

      Robot r;
      r.setup(id, x, y, w, vx, vy, vw);
      robots.push_back(r);
    }

    scanf("%d", &opponent_num_robots);

    for (int i = 0; i < opponent_num_robots; i++)
    {
      int id;
      float x, y, w, vx, vy, vw;
      scanf("%d %f %f %f %f %f %f", &id, &x, &y, &w, &vx, &vy, &vw);
      Robot r;
      r.setup(id, x, y, w, vx, vy, vw);
      opponent_robots.push_back(r);
    }

    // 
    world.ball().setup(ball_x, ball_y, ball_vx, ball_vy);

    printf("%d D %f %f %f\n", id_goalkeeper, -world.field_width() / 2, 0.0f, world.goal_width());

    if(ref_state == 'N')
    {
      // Estratégia que envia ao jogador mais próximo da bola a ordem de atacar e aos outros jogadores a ordem de defender no centro da área
      float dist_min = 999999999;
      int id_attacker;
      for (int i = 0; i < num_robots; i++)
      {
        if (robots[i].id() != id_goalkeeper)
        {
          float dist = dist_point({robots[i].x(), robots[i].y()}, {ball_x, ball_y});
          if (dist < dist_min)
          {
            dist_min = dist;
            id_attacker = robots[i].id();
          }
        }
      }

      printf("%d K\n", id_attacker);


      // Ponto em que a reta do gol até a bola intercepta a reta de defesa
      Point interPoint;
      bool isIntersect = line_intersect({-world.field_width() / 2, 0.0f}, {ball_x, ball_y},
          {-world.field_width() / 2 + world.defense_radius(), world.field_height() / 2}, {-world.field_width() / 2 + world.defense_radius(), -world.field_height() / 2},
          &interPoint);

      // TODO (rebeca - 20150304): Separar defesa defender linha em função
      float spacing = world.field_height() / (num_robots-1);
      int def_robots = 0;
      for (int i = 0; i < num_robots; i++)
      {
        if (robots[i].id() != id_goalkeeper && robots[i].id() != id_attacker)
        {
          def_robots++;
          printf("%d D %f %f\n",
              robots[i].id(), -world.field_width() / 2 + world.defense_radius(),
              world.field_height() / 2 - spacing * def_robots + (isIntersect ? interPoint.y() : 0.0f));
        }
      }
    }
    else if(ref_state == 'S')
    {
      // Ponto em que a reta do gol até a bola intercepta a reta de defesa
      Point interPoint;
      bool isIntersect = line_intersect({-world.field_width() / 2, 0.0f}, {ball_x, ball_y},
          {-world.field_width() / 2 + world.defense_radius(), world.field_height() / 2}, {-world.field_width() / 2 + world.defense_radius(), -world.field_height() / 2},
          &interPoint);
      int num_robots_center = 3;
      float spacing = world.field_height() / (num_robots-num_robots_center);
      int c_robots = 0, def_robots = 0;

      for(int i = 0; i < num_robots; i++)
      {
        if (robots[i].id() == id_goalkeeper)
          continue;

        if(c_robots < num_robots_center)
        {
          Point pos_final = {-world.field_width() / 2 - ball_x, 0.0f - ball_y};
          pos_final.normalize();
          pos_final.rotate(-60 + 60 * c_robots);
          printf("%d D %f %f\n",
                robots[i].id(), (pos_final.x() + ball_x) * world.center_circle_radius(), (pos_final.y() + ball_y) * world.center_circle_radius());
          c_robots++;
        }
        else
        {
          def_robots++;
          printf("%d D %f %f\n",
              robots[i].id(), -world.field_width() / 2 + world.defense_radius(),
              world.field_height() / 2 - spacing * def_robots + (isIntersect ? interPoint.y() : 0.0f));
        }
      }
    }
    else if(ref_state == 'i')
    {
      Point interPoint;
      bool isIntersect = line_intersect({-world.field_width() / 2, 0.0f}, {ball_x, ball_y},
          {-world.field_width() / 2 + world.defense_radius(), world.field_height() / 2}, {-world.field_width() / 2 + world.defense_radius(), -world.field_height() / 2},
          &interPoint);
      float spacing = world.field_height() / (num_robots - 2);
      int def_robots = 0;
      int used_robots = 0;
      int id_receiver;
      for (int i = 0; i < num_robots; i++)
      {
        if (robots[i].id() == id_goalkeeper)
          continue;

        else if(used_robots == 0)
        {
          id_receiver = robots[i].id();
          printf("%d A %f %f\n", id_receiver, world.field_width() / 4, 0.0f);
          used_robots++;
        }
        else if(used_robots == 1)
        {
          printf("%d P %d\n", robots[i].id(), id_receiver);
          used_robots++;
        }
        else
        {
          def_robots++;
          printf("%d D %f %f\n",
              robots[i].id(), -world.field_width() / 2 + world.defense_radius(),
              world.field_height() / 2 - spacing * def_robots + (isIntersect ? interPoint.y() : 0.0f));
        }
      }
    }
  }

  return 0;
}
