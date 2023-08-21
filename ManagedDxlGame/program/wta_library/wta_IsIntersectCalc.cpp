#include "wta_IsIntersectCalc.h"
#include <fstream>
#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"

namespace wta {
	
	//円と矩形の当たり判定計算
	bool IsIntersectCircleBox(const tnl::Vector3& circle, const int CircleSize, const tnl::Vector3& box, const int boxSize) {
		int boxSize_half = boxSize >> 1;					//矩形のサイズの半分（ビットシフト操作)
		int circle_squared = CircleSize * CircleSize;		//円の半径の2乗
		//�@矩形の上下左右辺の座標を求める
		int left_x = box.x - boxSize_half;
		int top_y = box.y - boxSize_half;
		int right_x = left_x + boxSize;
		int bottom_y = top_y + boxSize;
		//�A円の中心が矩形の内側にあるかどうかを判定する
		if (left_x <= circle.x && circle.x <= right_x && top_y <= circle.y && circle.y <= bottom_y) { return true; }	//円の中心が矩形の内側にある
		//�B円の中心が矩形の外側にある場合、円の中心と矩形の各辺との距離を求める
		//�B-1円の中心と矩形の各辺との距離を求める
		int dist_left_x = left_x - circle.x;		//左辺
		int dist_right_x = circle.x - right_x;		//右辺
		int dist_top_y = top_y - circle.y;			//上辺
		int dist_bottom_y = circle.y - bottom_y;	//下辺
		//�B-2円の中心と矩形の各辺との距離が円の半径より小さいかどうかを判定する
		if (dist_left_x >= 0 && dist_left_x <= CircleSize) { return true; }
		if (dist_right_x >= 0 && dist_right_x <= CircleSize) { return true; }
		if (dist_top_y >= 0 && dist_top_y <= CircleSize) { return true; }
		if (dist_bottom_y >= 0 && dist_bottom_y <= CircleSize) { return true; }
		//�C矩形の4隅の座標
		int corners[4][2] = {
			{left_x, top_y},       // 左上
			{right_x, top_y},      // 右上
			{left_x, bottom_y},    // 左下
			{right_x, bottom_y}    // 右下
		};
		//矩形の4隅の座標が円の内側にあるかどうかを判定する
		for (int i = 0; i < 4; i++) {
			int distance_squared = (corners[i][0] - circle.x) * (corners[i][0] - circle.x) +
				(corners[i][1] - circle.y) * (corners[i][1] - circle.y);
			if (distance_squared <= circle_squared) { return true; }
		}
		return false;
	}
	
	//---------------------------------------------------------------------------------------------
	//円と線分の当たり判定計算
	bool IsIntersectCircleLine(const tnl::Vector3& circle, const int CircleSize, const tnl::Vector3& lineStart, const tnl::Vector3& lineEnd) {
		int circle_squared = CircleSize * CircleSize;		//円の半径の2乗
		//�@線分の始点と終点のベクトルを求める
		tnl::Vector3 lineVec = lineEnd - lineStart;
		//�A線分の始点から円の中心までのベクトルを求める
		tnl::Vector3 circleVec = circle - lineStart;
		//�B線分の長さの2乗を求める
		float lineLengthPow = lineVec.x * lineVec.x + lineVec.y * lineVec.y;
		//�C線分の始点から円の中心までの距離を求める（内積）
		float dotProduct = lineVec.x * circleVec.x + lineVec.y * circleVec.y;
		//�D線分上の交点を計算
		float t = dotProduct / lineLengthPow;
		//�Etが0~1の間にある場合：線分上に交点が存在する
		if (t >= 0 && t <= 1.0f) {
			//�E-1交点から円の中心までの距離を計算
			tnl::Vector3 intersectionPoint;
			intersectionPoint.x = lineStart.x + t * lineVec.x;
			intersectionPoint.y = lineStart.y + t * lineVec.y;
			//�E-2距離の2乗を計算
			float distanceSquared = (intersectionPoint.x - circle.x) * (intersectionPoint.x - circle.x) +
				(intersectionPoint.y - circle.y) * (intersectionPoint.y - circle.y);
			//�E-3円の半径の2乗より小さい場合：円と線分は重なる
			if (distanceSquared <= circle_squared) { return true; }
		}
		//�Ftが外にある場合（線分両端の点と円の当たり判定を計算する）
		else {
			//�F-1線分の始点と円の中心の距離を計算
			tnl::Vector3 distance_start = lineStart - circle;
			//�F-2線分の終点と円の中心の距離を計算
			tnl::Vector3 distance_end = lineEnd - circle;
			//�F-3それぞれの長さを計算
			float distance_start_squared = distance_start.x * distance_start.x + distance_start.y * distance_start.y;
			float distance_end_squared = distance_end.x * distance_end.x + distance_end.y * distance_end.y;
			//�F-4円の半径の2乗より小さい場合、円と線分は重なる
			if (distance_start_squared <= circle_squared || distance_end_squared <= circle_squared) { return true; }
		}
		return false;
	}
	
	//---------------------------------------------------------------------------------------------
	//円同士の当たり判定計算
	bool IsIntersectCircleCircle(const tnl::Vector3& circle01, const int CircleSize01, const tnl::Vector3& circle02, const int CircleSize02) {
		//�@円の半径の和を計算
		int radius_sum = CircleSize01 + CircleSize02;
		//�A円の中心同士の距離を計算
		tnl::Vector3 distance = circle01 - circle02;
		//�B円の中心同士の距離の2乗を計算
		float distance_squared = distance.x * distance.x + distance.y * distance.y;
		//�C円の半径の和の2乗より小さい場合、円同士は重なる
		if (distance_squared <= radius_sum * radius_sum) { return true; }

		return false;
	}
}