class Foo
{
  public:
    std::string greeting;

    Foo()
    {
      greeting = "Hello";
    }

    Foo(std::string name) : Foo{}
    {
      greeting += " " + name;
    }
};