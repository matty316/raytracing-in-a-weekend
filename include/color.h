#pragma once

#include "interval.h"
#include "vec3.h"

using color = vec3;

void writeColor(std::ostream& out, const color& pixelColor) {
	auto r = pixelColor.x();
	auto g = pixelColor.y();
	auto b = pixelColor.z();
	
	static const interval intensity{ 0.000, 0.999 };
	int rByte = int(256 * intensity.clamp(r));
	int gByte = int(256 * intensity.clamp(g));
	int bByte = int(256 * intensity.clamp(b));

	out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}