# KNN classifier server :computer::books:
### ***Description:***
This project implements the famous KNN algorithm in c++.<br /> 
K-nearest neighbors algorithm is a non-parametric supervised learning method, It is used for classification and regression.<br />
The algorithm can calculate the distance between the input vectors to the classified vectors by using 5 different distance algorithms.<br />
**The five distance algorithms are:<br />**
* Euclidean distance<br /> 
* Taxicab geometry<br /> 
* Chebyshev distance<br /> 
* Canberra distance<br /> 
* Minkowski distance<br /><br /> 
The project based on the TCP transport protocol can connect to several clients in parallel.

**The server display a five option menue to the client:<br/>**
* 1- The server asks for a double multidimensional classified vectors CSV file and an unclassified vectors CSV file.<br/>
The vectors contain doubled numbers that can appear with their sign +,- or with .<br />
if the classified vectors and the unclassified vectors are not comparable i.e isn't in the same size the server will return the following error message:<br/>
`ERROR - "ERROR"`<br />
If the vectors in both files are valid (in the same size and have double numbers) the server loads the data.<br/>
Also the number of classified vectors could be >= to the algorithm's k neighbors, if not the server will return the following error message:<br/>
`ERROR - "ERROR"`<br />
* 2- The server displays the number of neighbors and the matric distance name of the algorithm calculation, the user can change these parameters by writing a string in this format ``` 4 MAN ```. <br/>By type enter the k neighbors and the matric will stay the same.<br/>
* 3- Finds the classification according to the KNN algorithm for each unclassified vector.<br/> 
If the usert didn't press 1 already the server would return the following error message:<br/>
`ERROR - "ERROR"`<br /> 
* 4- Prints the classification vectors data to the screen.<br/>
If the usert didn't press 1 and 3 already the server will return the following error message:<br/>
`ERROR - "ERROR"`<br /> 
* 5- Gets a file path from the user and saves the classification vector data in this file.<br/>
If the usert didn't press 1 and 3 already the server would return the following error message:<br/>
`ERROR - "ERROR"`<br /><br/>


### ***How to run the Project?<br />***
Type "make" in the cmd<br />
#### first we sould run the server.
run it with the command line: server.out port<br />
when:<br />
* port is the choosen port, the port can be a number between 0 to 65535<br /><br /> 
#### secound we sould run the client in other terminal.
run it with the command line: client.out ip port<br />
when:<br />
* ip the computer's ip, expressed as a set of four numbers. Each number in the set can range from 0 to 255.<br/>
* port is the choosen port, the port sould be the same as the port in the server's command line<br /> 

### ***The distances calculation implementation:<br />***
To calculate the varity of the distances calculation we use auxiliary function that gets 2 double numbers x, y, int i and do the following calculation: $${|x-y|^i} $$
+ **Euclidean distance:** in this function the algorithm use the auxiliary function that mention above, when xj and yj are the numbers in the vectors at the j index and i=2.<br />
after summing all the valuse we sqrt the sum according to the formula:<br />![image](https://user-images.githubusercontent.com/117579573/202558834-7df913ce-1770-49ab-b0ec-26a8eaf5993b.png)<br />
+ **Taxicab geometry:** the Taxicab algorithm is Minkowski algorithm when p=1;<br />
![image](https://user-images.githubusercontent.com/117579573/202560676-5112300a-0e4b-4c02-b8f3-9a24013c123f.png)
+ **Chebyshev distance:** in Chebyshev function we use the auxiliary function when xj and yj are the numbers in the vectors at the j index and i=1.
the function returns the max value that we get from the auxiliary function<br />
![image](https://user-images.githubusercontent.com/117579573/202561662-a32569c4-53ef-4a53-9ea2-64e7d961005a.png)
+ **Canberra distanc:** in this function we use again in the auxiliary function with i=1. according to the canberra formola.
In case we get 0 in the denominator (it can occur when in xi=yi=0) the function refers to the sum value at the i index as 0, i.e doesn't adding nothing to the sigma in the i calculation.<br />
![image](https://user-images.githubusercontent.com/117579573/202562806-9bced31a-7797-4001-a3a9-3a2ca7637b2b.png)
+ **Minkowski distanc:** in this function we use again in the auxiliary function with i=p=2 (in our code set p=2).
![image](https://user-images.githubusercontent.com/117579573/202564633-69501cfb-c6fe-4a41-875b-7588042507f5.png)<br /><br />
