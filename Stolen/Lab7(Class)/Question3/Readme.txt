#ID : 175    Question 2Number of sumissions: 0/50Expired time: 2019-05-24 12:15:00
Given Integer class as follows:


class Integer {


int value;


public:


};


Write some member functions to define "equal" operator, "greater than" operator, "less than" operator, and all other operators needed,


so that these following code can find the maximum number of an Integer array.


Integer max(Integer* arr, Integer numberOfElements) {


if (arr == NULL || numberOfElements == 0) return Integer(-1);


Integer max = arr[0];


for (Integer i = 0; i < numberOfElements; i = i + 1) {


if (arr[i] > max) max = arr[i];


}


return max;


}