#include <cstdio>
#include <cstring>

#define PROTOCOLO_VERSAO 1

int main()
{
	// Pre setup
	char protocolo[64];
	int versao;
	scanf("%s %d", protocolo, &versao);
	if (strcmp(protocolo, "ROBOIME_AI_PROTOCOL_VERSION") == 0 && versao == PROTOCOLO_VERSAO)
		printf("COMPATIBLE %d\n", PROTOCOLO_VERSAO);
	else
		printf("NON_COMPATIBLE %d\n", PROTOCOLO_VERSAO);

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

    	scanf("%c %f", &ref_state, &timestamp);
    	scanf("%f %f %f %f", &ball_x, &ball_y, &ball_vx, &ball_vy);
    	scanf("%d %d", &id_goalkeeper, &num_robots);

    	for(int i = 0; i < num_robots; i++)
    	{
    		int robot_id;
    		float robot_x, robot_y, robot_w,
    			  robot_vx, robot_vy, robot_vw;
    		scanf("%d %f %f %f %f %f %f", &robot_x, &robot_y, &robot_w, &robot_vx, &robot_vy, &robot_vw);
    	}

    	scanf("%d", &opponent_num_robots);

    	for(int i = 0; i < opponent_num_robots; i++)
    	{
    		int robot_id;
    		float robot_x, robot_y, robot_w,
    			  robot_vx, robot_vy, robot_vw;
    		scanf("%d %f %f %f %f %f %f", &robot_x, &robot_y, &robot_w, &robot_vx, &robot_vy, &robot_vw);
    	}
    }

    return 0;
}