#pragma once

class Vec3;

class AABB {
public:
	static AABB EMPTY;
	static AABB MIN;

public:
	// Size : 27
	bool _b1;		// 0
	float _x1;		// 4
	float _y1;		// 8
	float _z1;		// 12
	float _x2;		// 16
	float _y2;		// 20
	float _z2;		// 24

public:
	AABB(void);
	AABB(const Vec3 &, float);
	AABB(const Vec3 &, const Vec3 &);
	AABB(float, float, float, float, float, float);
	void clip(const Vec3 &, const Vec3 &) const;
	void clipXCollide(const AABB &, float) const;
	void clipYCollide(const AABB &, float) const;
	void clipZCollide(const AABB &, float) const;
	void cloneMove(const Vec3 &) const;
	bool contains(const Vec3 &) const;
	void copy() const;
	void expand(const Vec3 &);
	void expanded(float, float, float);
	void flooredCeiledCopy() const;
	void flooredCopy(float, float) const;
	void getBounds() const;
	void getSize() const;
	void grow(const Vec3 &) const;
	void intersects(const AABB &) const;
	void intersectsInner(const AABB &) const;
	bool isEmpty() const;
	bool isNan() const;
	void merge(const AABB &) const;
	void move(float, float, float);
	void set(const AABB &);
	void set(const Vec3 &, const Vec3 &);
	void set(float, float, float, float, float, float);
	void shrink(const Vec3 &);
	std::string toString() const;
	void translated(const Vec3 &) const;
};
