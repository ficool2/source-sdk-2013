//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//=============================================================================//

#ifndef VRADDETAILPROPS_H
#define VRADDETAILPROPS_H
#ifdef _WIN32
#pragma once
#endif


#include "bspfile.h"
#include "mathlib/anorms.h"

#define LIGHTMODE_INDIRECT_LAST	(LIGHTMODE_INDIRECT_COUNT - 1)

enum
{
	LIGHTMODE_INDIRECT_DOT,
	LIGHTMODE_INDIRECT_INVSQRLAW,
	LIGHTMODE_INDIRECT_PURE,

	LIGHTMODE_INDIRECT_COUNT
};

// Calculate the lighting at whatever surface the ray hits.
// Note: this ADDS to the values already in color. So if you want absolute
// values in there, then clear the values in color[] first.
void CalcRayAmbientLighting(
	int iThread,
	const Vector &vStart,
	const Vector &vEnd,
	float tanTheta,			// tangent of the inner angle of the cone
	Vector color[MAX_LIGHTSTYLES]	// The color contribution from each lightstyle.
	);

bool CastRayInLeaf( int iThread, const Vector &start, const Vector &end, int leafIndex, float *pFraction, Vector *pNormal );

void ComputeDetailPropLighting( int iThread );


#endif // VRADDETAILPROPS_H
