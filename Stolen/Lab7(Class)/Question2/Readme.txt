#ID : 174    Question 1b  Number of sumissions: 1/50Expired time: 2019-05-24 12:15:00
Given Integer class as follows:



class Integer {


	int value;


public:


	


};


These following code is about creating an Integer object.


We want to store a double number "d" as "value" attribute of Integer object "i".


Then, from the "value" we have, convert it to a string and print it on screen.


Complete the given Integer class so that all requests are served.



void process(double d) {


	Integer i = d;


	char* c = NULL;


	i.toString(c);


	cout << c;


	delete[] c;


}

