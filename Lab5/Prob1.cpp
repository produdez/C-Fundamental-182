//a
int *number;
cout << number << endl; //Correct

//b
int * x, y;
x = y; //Different types

//c
char s[] = "this is a character array";
for ( ; *s != '\0'; s++) //Array name is constant pointer so we cant increase s, thus making an error
cout << *s << ' ';

//d
double x = 19.34;
double xPtr = &x; //Can't initialize a double value with a *double (pointer) value
cout << xPtr << endl;
