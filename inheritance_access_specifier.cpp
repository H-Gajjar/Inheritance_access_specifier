/*
 *
 *  Created on: Dec 31, 2020
 *      Author: Hardik
 *
 *  This program tries to demonstrate all the possible use case of access specifier in inheritance.
 *  What is Inheritance access specifier ?
 *  - Inheritance access specifiers are used to define the accessibity of the subsequent members
 *    of the base class. There are three types of the access specifiers.
 *    1. public -> This is the most common type of the access specifier in inheritance because It
 *    			   maintains the same scope of base class members in derived class.
 *    			   With public access specifier, all the public members of base class remains public
 *    			   in derived class and all the protected members of the base class remains protected
 *    			   in derived class. Inheritance access specifier is not applicable on private members.
 *    2. protected -> This access specifier defines all (protected and public) variables of the base class
 *                    as protected in the derived class.
 *    3. private -> This access specifier defines all (protected and public) variables of the base class
 *                    as private in the derived class. Therefore, they are neither used outside of the
 *                    class nor in derived class. (derived class means the class used as base class with another class)
 */

#include <iostream>

using namespace std;

class A {
	int a;
protected:
	int b;
public:
	int c;
	A();
	~A();
	virtual void print() = 0;

};

A::A():a(0), b(0), c(0) {

}

A::~A() {

}

/** All the members(public & protected) of Class A are defined as private in Class B **/

/** All the private member of Class A remains private for all scope
 *  unless class or function declare as friend explicitly.
 */


class B : private A {
public:
	void print () {
			/** We cannot access private member of base class */
			//cout << "  a : " << a <<endl;

			/* Can access b & c within this class but the private variable of this class */
			cout << __func__ << ":  b = " << b <<endl;
			cout << __func__ << ":  c = " << c <<endl;
		}
};

/**
 * All the members of Class A are private in class B, Therefore, we cannot
 * use it in Class BB.
 * here ignore the inheritance access specifier of class B
 */
class BB : public B {
	void print () {
				/** We cannot access private member of base class */
				//cout << "  a : " << a <<endl;

				/* Cannot access b & c within this class because they are private in class B*/
				//cout << __func__ << ":  b = " << b <<endl;
				//cout << __func__ << ":  c = " << c <<endl;
			}
};

/** All the members(public & protected) of Class A are defined as protected in Class C **/

/** All the private member of Class A remains private for all scope
 *  unless class or function declare as friend explicitly.
 */
class C : protected A {
public:
	void print () {
		/** We cannot access private member of base class */
		//cout << "  a : " << a <<endl;

		/* Can access b & c within this class but the protected variable of this class */
		cout << __func__ << ":  b = " << b <<endl;
		cout << __func__ << ":  c = " << c <<endl;
	}
};

/**
 * All the members of Class A are protected in class C, Therefore, we can use it in Class CC.
 * here ignore the inheritance access specifier of class D
 */
class CC : private C {
public:
	void print () {
		/** We cannot access private member of base class */
		//cout << "  a : " << a <<endl;

		/* Can access b & c within this class as they are protected in base class C */
		cout << __func__ << ":  b = " << b <<endl;
		cout << __func__ << ":  c = " << c <<endl;
	}
};

/** public members of Class A are defined as public and
 *  protected members of Class A are defined as protected in Class D**/

/** All the private member of Class A remains private for all scope
 *  unless class or function declare as friend explicitly.
 */
class D : public A {
public:
	void print () {
		/** We cannot access private member of base class */
		//cout << "  a : " << a <<endl;

		/* Can access b & c within this class but variable b & c are
		 * protected and public respectively in this class
		 */
			cout << __func__ << ":  b = " << b <<endl;
			cout << __func__ << ":  c = " << c <<endl;
		}
};

/**
 * All the members of Class D are inherited with same access scope , Therefore, we can use it in Class CC.
 * here ignore the inheritance access specifier of class D
 */
class DD : private D {
public:
	void print () {
		/** We cannot access private member of base class */
		//cout << "  a : " << a <<endl;

		/* Can access b & c within this class */
		cout << __func__ << ":  b = " << b <<endl;
		cout << __func__ << ":  c = " << c <<endl;
	}
};

int main (void) {
	B b;
	b.print();
# if 1
	/* Let's try to access the b & c via Class B */
	//cout << "  b : " << b.b << endl;
	//cout << "  c : " << b.c << endl;
	/* We cannot access any members out side derived class because base class A inherited with
	 * private access specifier.*/

	C c;
	c.print();

	/* Let's try to access the b & c via Class C */
	//cout << "  b : " << c.b << endl;
	//cout << "  c : " << c.c << endl;
	/* We cannot access any members out side derived class because base class A inherited with
	 * protected access specifier.*/
#endif
	D d;
	d.print();

	/* Let's try to access the b & c via Class D */
	//cout << "  b : " << d.b << endl;
	cout << "c : " << d.c << endl;
	/* We can access 'c' because base class A inherited with public access specifier
	 * but cannot access "b" because it is protected in base class.
	 * protected members can only access in self and derived class*/

	return 0;
}


