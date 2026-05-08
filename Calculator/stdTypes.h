/*
 * stdTypes.h
 *
 * Created: 8/6/2025 12:39:41 PM
 *  Author: BS
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_


///unsigned int types
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long long u32;

///signed int types:
typedef signed char s8;
  //it's okay not to write signed because numbers are signed by default
typedef signed int s16;
typedef signed long long s32;

/// floating point types:
typedef float f16;
typedef double f32;

typedef enum{FALSE=0 , TRUE=1} bool_t;


#endif /* STDTYPES_H_ */