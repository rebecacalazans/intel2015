#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

#define PROTOCOL_VERSION 1

struct Robot
{
  int id;
  float x, y, w,
        vx, vy, vw;
};

float dist_point(Robot a, float x, float y)
{
  return sqrt( (a.x - x) * (a.x - x) + (a.y - y)*(a.y - y) );
}

int main()
{
  // Pre setup
  char protocol[64];
  int version;
  scanf("%s %d", protocol, &version);
  if (strcmp(protocol, "ROBOIME_AI_PROTOCOL_VERSION") == 0 && version == PROTOCOL_VERSION)
    printf("COMPATIBLE %d\n", PROTOCOL_VERSION);
  else
    printf("NON_COMPATIBLE %d\n", PROTOCOL_VERSION);

  // Setup
  float field_width,
        field_height,
        goal_width,
        center_circle_radius,
        defense_radius,
        defense_stretch,
        free_kick_from_defense_dist,
        penalty_spot_from_field_line_dist,
        penalty_line_from_spot_dist;
  scanf("%f %f %f %f %f %f %f %f %f",
      &field_width,
      &field_height,
      &goal_width,
      &center_circle_radius,
      &defense_radius,
      &defense_stretch,
      &free_kick_from_defense_dist,
      &penalty_spot_from_field_line_dist,
      &penalty_line_from_spot_dist);

  while (true)
  {
    char ref_state;
    float timestamp;
    float ball_x, ball_y, ball_vx, ball_vy;
    int id_goalkeeper,
        num_robots,
        opponent_num_robots;

    std::vector<Robot> robots,
      opponent_robots;

    scanf(" %c %f", &ref_state, &timestamp);
    scanf("%f %f %f %f", &ball_x, &ball_y, &ball_vx, &ball_vy);
    scanf("%d %d", &id_goalkeeper, &num_robots);

    /*
    printf("ref: %c\n", ref_state);
    printf("timestamp: %f\n", timestamp);
    printf("ball: %f %f %f %f\n", ball_x, ball_y, ball_vx, ball_vy);
    printf("id_goalkeeper: %d\n", id_goalkeeper);
    printf("num_robots: %d\n", num_robots);
    */

    for (int i = 0; i < num_robots; i++)
    {
      Robot r;
      scanf("%d %f %f %f %f %f %f", &r.id, &r.x, &r.y, &r.w, &r.vx, &r.vy, &r.vw);
      robots.push_back(r);
    }

    /*
    printf("robots [%zd]: ", robots.size());
    for (unsigned int i = 0; i < robots.size(); ++i)
      printf("%d ", robots[i].id);
    printf("\n");
    */

    scanf("%d", &opponent_num_robots);

    for (int i = 0; i < opponent_num_robots; i++)
    {
      Robot r;
      scanf("%d %f %f %f %f %f %f", &r.id, &r.x, &r.y, &r.w, &r.vx, &r.vy, &r.vw);
      opponent_robots.push_back(r);
    }

    // Estratégia que envia ao jogador mais próximo da bola a ordem de atacar e aos outros jogadores a ordem de defender no centro da área
    float dist_min = 999999999;
    int id_attacker;
    printf("%d D %f %f\n", id_goalkeeper, -field_width / 2, 0.0f);
    for (int i = 0; i < num_robots; i++)
    {
      if (robots[i].id != id_goalkeeper)
      {
        float dist = dist_point(robots[i], ball_x, ball_y);
        if (dist < dist_min)
        {
          dist_min = dist;
          id_attacker = robots[i].id;
        }
      }
    }

    printf("%d K\n", id_attacker);

    float spacing = field_height / (num_robots-1);
    int def_robots = 0;
    for (int i = 0; i < num_robots; i++)
    {
      if (robots[i].id != id_goalkeeper && robots[i].id != id_attacker)
      {
        def_robots++;
        printf("%d D %f %f\n", robots[i].id, -field_width / 2 + defense_radius, field_height / 2 - spacing * def_robots);
      }
    }

#ifdef DEBUG
    return 1;
#endif
  }

  return 0;
}
