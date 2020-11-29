class A extends Object
{
	P2 a;
	
	A (P2 a) { super(); this.a = a; }

	P2 m() {return this.a; }
}

class B extends A
{
	Object o1;
	Object o2;
	
	B(P2 a, Object o2, Object o1) { super(a); this.o1  =o1; this.o2=o2; }
	
	P2 m() {return (new P2(this.o1)); }
}

class C extends B
{
	C(P2 a, Object o1, Object o2){ super(a, o1, o2); }

	P3 m2(P1 p1, P2 p2 ) { return (new P3(p1.o1)); }
}

class P1 extends Object
{
	Object o1;

	P1(Object o1) {super(); this.o1 = o1; }
}

class P2 extends P1
{
	P2(Object o1) {super(o1); }
}

class P3 extends P2
{
	P3(Object o1) {super(o1); }
}