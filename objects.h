/**************************************************************************
 *									  *
 *  Copyright (C)  1988 Silicon Graphics, Inc.	  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/

/* objects			*/
/* 0 => 8 reserved for plane views	*/
/* 9 => 9+MEXPLODE reserved for explosion	*/
#define mtn_dist 100
#define mtn_left 100000

#define EXPLOSION 9

#define REPORT_CARD 20

#define FOV_EDIT 40
#define PUSH_IDENTITY 43
#define MTN_RANGE 44

#define DRAW_SKY 48
#define SETUP_WORLD 50
#define WORLD_OBJECT 51
#define CROSS_HAIRS 52
#define CLEAR_TEXT_DISPLAY 53
#define CLEAR_REPORT_CARD 54
#define RUNWAY_STRIPES 55
#define FAKE_STRIPES 56
#define BUILDINGS 57
#define METER_OVERLAY 60
#define HORIZON_METER 61
#define HEADING_METER 62
#define CLEAR_METERS 63
#define CLEAR_FUEL_METER 64
#define SLOW_METERS 65
#define WING_STALL 66
#define CRASH_METERS 67
#define G_LIMIT 68
#define AUTO_PILOT 69
#define LIGHTS 74
#define VASI1 77
#define VASI2 78

#define HEADING_ROTATE_EDIT 100
#define HORIZON_EDIT 101
#define RADAR 102
#define YAW_EDIT 103
#define TEXT_EDIT 104
#define VV_EDIT 105
#define GY_EDIT 106
#define RHAWS_EDIT 107

/* reserve BUILDING_OBJECTS to BUILDING_OBJECTS + MAX_BUILDINGS*4 */
#define MAX_BUILDINGS 5000000
#define BUILDING_OBJECTS 125
#define WHEEL_ANGLE 960
#define LWHEEL_ANGLE 961
#define RWHEEL_ANGLE 962
#define FWHEEL_ANGLE 963

#define C150 1000
#define B747 1010
#define F15  1020
#define F16  1030
#define F18  1040
#define P38  1050
#define F16W 1060
#define P38W 1070
#define SC_WORLD 1100
#define HOUSE		4000
#define HOUSES		4001
#define TREE		4002
#define TEXTCUBE	4003
#define MYMOUNTAIN	4004

#define C150_NAME "C-150"
#define B747_NAME "B-747"
#define F15_NAME "F-15"
#define F16_NAME "F-16"
#define F18_NAME "F-18"
#define P38_NAME "P-38"

#define PLANE_BIT 0x80000000	/* used to flag a plane pointer	*/
#define TYPE_BUILDING 0
#define TYPE_MOUNTAIN 1
#define TYPE_THREAT 2
#define TYPE_HOUSE 3
#define TYPE_TREE 4

#define AIR_STRIP	9999
#define DEBUG_TEXT	9090
#define HUD			9091
#define COCKPIT		9092
#define BUILDINGS_OFFSET 10000
void make_my_building(int obj, int col, int llx, int lly, int llz, int dx, int dy, int dz, float segments);
void make_house();
void make_tree();
void init_textures();
void init_light(float sunpos);
void free_camera(struct gameState *gs);
void make_textures_cube();
void create_pattern();
void make_mountain_zone(int x, int y, int size, struct gameState *gs);