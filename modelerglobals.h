#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls
{
	LIGHTR,
	LIGHTG,
	LIGHTB,
	INTENSITY,
	XPOS,
	YPOS,
	ZPOS,
	RIGHTARMX,
	RIGHTARMY,
	RIGHTARMZ,
	RIGHTELBOWX,
	RIGHTELBOWY,
	RIGHTHANDX,
	LEFTARMX,
	LEFTARMY,
	LEFTARMZ,
	LEFTELBOWX,
	LEFTELBOWY,
	LEFTHANDX,
	RIGHTLEGX,
	RIGHTLEGZ,
	RIGHTKNEE,
	LEFTLEGX,
	LEFTLEGZ,
	LEFTKNEE,
	FAT,
	MOUTHANGLE,
	DETAILEDHAND,
	TEXTURE,
	JETBACKPACK,
	TORUSHALO,
	METABALLSKIN,
	METABALLSIZE,
	METABALLTHRESHOULD,
	NUMCONTROLS
};

// Size Symbolic Constants
#define CHEST_HALFHEIGHT 1.4f
#define BELLY_HALFHEIGHT 1.0f
#define HEAD_HALFHEIGHT 0.6f
#define SHOULDER_RADIUS 1.1f
#define WAIST_RADIUS 0.8f
#define HIP_RADIUS 1.2f
#define UPPERARM_RADIUS 0.3f
#define UPPERARM_LENGTH 1.0f
#define FOREARM_RADIUS 0.2f
#define FOREARM_LENGTH 1.2f
#define HAND_LENGTH 0.5f
#define THIGH_LENGTH 1.0f
#define THIGH_RADIUS 0.3f
#define SHANK_LENGTH 1.2f
#define SHANK_RADIUS 0.25f

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define GETVAL(x) (ModelerApplication::Instance()->GetControlValue(x))
#define SETVAL(x, y) (ModelerApplication::Instance()->SetControlValue(x, y))
#endif