int main()
{
    char str[] = "We Are Happy";    //注意后面还有\0
    replaceSpace(str, 13);
    cout << str << endl;

    string s("We Are Happy");
    cout << fun(s) << endl;
}