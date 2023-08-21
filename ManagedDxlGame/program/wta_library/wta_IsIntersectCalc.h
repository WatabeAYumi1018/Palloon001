#pragma once
#include <vector>
#include "tnl_math.h"

namespace wta {

	//�~�Ƌ�`�̓����蔻��v�Z
	bool IsIntersectCircleBox(const tnl::Vector3& circle, const int CircleSize, const tnl::Vector3& box, const int boxSize);

	//�~�Ɛ����̓����蔻��v�Z
	bool IsIntersectCircleLine(const tnl::Vector3& circle, const int CircleSize, const tnl::Vector3& lineStart, const tnl::Vector3& lineEnd);

	//�~���m�̓����蔻��v�Z
	bool IsIntersectCircleCircle(const tnl::Vector3& circle01, const int CircleSize01, const tnl::Vector3& circle02, const int CircleSize02);
}