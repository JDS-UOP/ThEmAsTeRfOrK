#ifndef _DEFINITION_H
#define _DEFINITION_H

#include "mbed.h"
#include "params.h"
#include <cstdint>

typedef uint16_t u16;
typedef uint16_t* u16p;
typedef int16_t i16;
typedef int16_t* i16p;

typedef struct {
    u16 TRACKING_ERROR : 1;
    u16 RESERVED : 7;
    u16 AXIS_ERROR : 8; }
CONTROLLER_ERROR;

typedef struct { 
    u16 x;
    u16 y;
    u16 z; }
VECTOR3D;

typedef struct { 
    float x;
    float y;
    float z; }
VECTOR3Df;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u16 a;
    u16 b;
    u16 c; }
VECTOR6D;

typedef struct {
    float x;
    float y;
    float z;
    float a;
    float b;
    float c; }
VECTOR6Df;

typedef struct {
    VECTOR3Df q;
    VECTOR3Df V;
    VECTOR3Df t; }
ARM_CARTESIAN_VARIABLES;

typedef struct {
    u16 J1;
    u16 J2;
    u16 J3;
    u16 J4;
    u16 J5; } 
POSE;

typedef struct {
    u16 controlPos;
    u16 controlVel;
    u16 torqueFF;
    u16 integratorLimit; }
MOTOR_CONTROL_TETRA;


typedef struct {
    u16 currentPos;
    u16 currentVel;
    u16 currentTorque;
    u16 motorAxisState; }
MOTOR_STATE_TETRA;

typedef struct {
    u16 currentPos;
    u16 currentVel;
    u16 currentTorque; }
JOINT_STATE_TRIPLET;

typedef struct {
    u16 controlPos;
    u16 controlVel;
    u16 torqueFF; }
JOINT_CONTROL_TRIPLET;

typedef struct {
    u16 reserved : 1;
    u16 isPowered : 1;
    u16 powerAllowed : 1;
    u16 isHomed : 1;
    u16 error : 1;
    u16 maxStrokeHit : 1;
    u16 minStrokeHit : 1;
}
JOINT_STATE;



VECTOR3Df add3DF(VECTOR3Df a, VECTOR3Df b);
VECTOR3Df invert3DF(VECTOR3Df a);
VECTOR6Df add6DF(VECTOR6Df a, VECTOR6Df b);
VECTOR3Df evaluateTrackingError(VECTOR3Df iC, VECTOR3Df rC);
bool isGreater3Df(VECTOR3Df var, VECTOR3Df param);


#endif