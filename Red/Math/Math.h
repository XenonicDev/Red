#pragma once

#include "../Core/Definitions.h"
#include "Vector.h"
#include "Quaternion.h"

namespace Red
{
	namespace Math
	{
		const Vector3 Vector3::ZeroVector(0, 0, 0);
		const Vector3 Vector3::ForwardVector(1, 0, 0);
		const Vector3 Vector3::RightVector(0, 1, 0);
		const Vector3 Vector3::UpVector(0, 0, 1);

		const Quaternion Quaternion::ZeroQuaternion(0, 0, 0, 0);
		const Quaternion Quaternion::IdentityQuaternion(0, 0, 0, 1);

		uint64 Factorial(uint32 Factor)
		{
			return (Factor == 1 ? 1 : Factor * Factorial(Factor - 1));
		}
	}  // namespace Math
}  // namespace Red