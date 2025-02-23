🔹 Key Differences
Feature                          struct                              	class
Default Access Modifier      public	                                    private
Purpose	                     Used for plain data structures             Object Oriented tasks
	
Encapsulation	             Weak (everything is public by default)	    Strong (everything is 
                                                                        private by default)
Inheritance	                 Inherits publicly by default	            Inherits privately by default 


1️⃣ Using struct

struct MyStruct {
    int x;  // Default: public
};

int main() {
    MyStruct obj;
    obj.x = 10;  // ✅ Allowed (public)
    return 0;
}

2️⃣ Using class

class MyClass {
    int x;  // Default: private
};

int main() {
    MyClass obj;
    obj.x = 10;  // ❌ Error: x is private
    return 0;
}


🔹 When to Use struct vs class
✅ Use struct when:

You are working with simple data structures.
You don't need encapsulation or private members.
Example: Binary Tree, Linked List Nodes.
✅ Use class when:

You are designing full-fledged objects with data hiding.
You need encapsulation and private members.
Example: OOP-based systems like Student, Account, Vehicle.