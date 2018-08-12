/* Consider the isosceles triangle with base length, b = 16, and legs, L = 17.
 * By using the Pythagorean theorem it can be seen that the height of the triangle,
 * h = sqrt(172 - 82) = 15, which is one less than the base length.
 *
 * With b = 272 and L = 305, we get h = 273, which is one more than the base length,
 * and this is the second smallest isosceles triangle with the property that h = b +/- 1.
 *
 * Find E L for the twelve smallest isosceles triangles for which h = b +/- 1 and b, L
 * are positive integers
 *
 * */

#include"isosceles.h"

struct sides
{
	int A;
	int B;
	int C;
};

struct angles
{
	int a;
	int b;
	int c;
};

struct triangle
{
	struct sides side;
	struct angles angle;
};

static int IsTriangleValid(struct triangle t);
static int AreAnglesConsistentWithSides(struct triangle t);

extern int Iso_Init(void)
{
	struct triangle t;

	t.side.A = 5;
	t.side.B = 3;
	t.side.C = 3;

	t.angle.a = 90;
	t.angle.b = 45;
	t.angle.c = 45;

	return IsTriangleValid(t);
}

static int IsTriangleValid(struct triangle t)
{
	int validAngleSum = (t.angle.a + t.angle.b + t.angle.c) == 180;
	int sameSides = t.side.B == t.side.C;
	int sameBaseAngles = t.angle.b == t.angle.c;

	if (validAngleSum && sameSides && sameBaseAngles)
		return 1;
	else
		return 0;
}

static int AreAnglesConsistentWithSides(struct triangle t)
{
	int consistent;
	int halfBase = t.side.A / 2;

	int h = sqrt(((t.side.C * t.side.C) - (halfBase * halfBase)));
//find angle based on sine
}
