/* in shared pointers more than one pointer will share the same object and all the shared  pointers will
   have the owership to that particular object.
*/

#pragma warn

#include <iostream>
#include <memory>

using namespace std;

void start_Up(void);
void wind_Up(void);

#pragma startUp start_Up
#pragma end wind_Up

class foo
{
  private:
    int var_one;
    string type_ptr;

  public:
    foo();
    foo(string type_ptr);
    void edit_Data(int);
    int return_Data();
    ~foo() { cout << "\nfoo is cleared..."; }
};

foo::foo()
{
    cout << "\ncreated a shared pointer";
}

foo::foo(string type_ptr)
{
    this->type_ptr = type_ptr;
    cout << "\ncreated a" << type_ptr << " pointer...";
    var_one = 0;
}

void foo::edit_Data(int var_one)
{
    this->var_one = var_one;
}

int foo::return_Data()
{
    return var_one;
}

int main()
{
    cout << "\n\nblock one : \n";
    {
        shared_ptr<foo> ptr_one(new foo(), [](foo *ptr) {
            cout << "\nCustom delete ";
            delete ptr; });
        ptr_one->edit_Data(18);
        cout << "\nedited data is : " << ptr_one->return_Data();
        cout << "\nnumber of shared pointers are : " << ptr_one.use_count();

        {
            shared_ptr<foo> ptr_two = ptr_one;
            cout << "\nedited data is : " << ptr_two->return_Data();
            cout << "\nnumber of shared pointers are : " << ptr_one.use_count() << "  " << ptr_two.use_count();
            ptr_two->edit_Data(-15);

            cout << "\nedited data is : " << ptr_one->return_Data();

            ptr_one = nullptr;

            cout << "\nnumber of shared pointers are : " << ptr_one.use_count();
            cout << "\nnumber of shared pointers are : " << ptr_two.use_count();
        }
        cout << "\nnumber of shared pointers are : " << ptr_one.use_count();
    }

    cout << "\n\nblock two : ";
    {
        foo *raw_ptr = new foo(" raw pointer");
        shared_ptr<foo> ptr_three(raw_ptr);
        shared_ptr<foo> ptr_four(raw_ptr);

        cout << "\ncount three : " << ptr_three.use_count() << "   count four : " << ptr_four.use_count();

        cout << "\n";

        shared_ptr<foo> ptr_five = make_shared<foo>();
        shared_ptr<foo> ptr_six(ptr_five);

        cout << "\ncount five : " << ptr_five.use_count() << "   count six : " << ptr_six.use_count();
    }

    cout << "\n\nblock three : ";
    {
        shared_ptr<foo> ptr_array = shared_ptr<foo>(new foo[3], [](foo *ptr) {cout<<"\ndeleting array"; delete[] ptr; });
        ptr_array = nullptr;

        cout << "\ncount : " << ptr_array.use_count();
    }

    cout << "\n\nblock four";
    {
    }

    cout << "\n\nblock five : ";
    {

        shared_ptr<int> ptr_one = make_shared<int>(5);
        cout << "\nptr int : " << (*ptr_one) << " count : " << ptr_one.use_count();

        shared_ptr<int> ptr_two(ptr_one);

        cout << "\nptr int : " << (*ptr_two) << " count : " << ptr_two.use_count();

        ptr_one.reset();

        cout << "\nptr int : " << (*ptr_two) << " count : " << ptr_two.use_count();
        cout << "\nptr int : " << (*ptr_two) << " count : " << ptr_one.use_count();
    }

    cout << "\n";
    system("pause");
    return 0;
}

void start_Up(void)
{
    cout << "\nlets go...";
}

void wind_Up(void)
{
    cout << "\nEnding task...";
}