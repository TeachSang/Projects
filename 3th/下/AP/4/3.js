"use strict";

const testlib = require( './testlib.js' );
var list=new Array(); //To store data
var pattern; //To store patterns
var a = 0;

/** This method is used to put the patterns in the array, 
 * and show it at first line
 * @author Sang Haotian
 */
testlib.on( 'ready', function( patterns ) {
	console.log( "Patterns:", patterns );
	pattern=patterns;

	testlib.runTests();
});

/** This method is used to store data, 
 * show the offset of specific gene sequences
 * store the amount of specific gene sequences
 * show them on the screen.
 * @author Sang Haotian
 */
testlib.on( 'data', function(store){
	list[a]=store;
	a++;
	testlib.on( 'end', function(store){
		//To put all gene type in an object which used to check
		var genes = {
			C:['C'],
			G:['G'],
			A:['A'],
			T:['T'],
			R:['G','A','R'],
			Y:['T','C','Y'],
			K:['G','T','K'],
			M:['A','C','M'],
			S:['G','C','S'],
			W:['A','T','W'],
			B:['G','T','C','B'],
			D:['G','A','T','D'],
			H:['A','C','T','H'],
			V:['G','C','A','V'],
			N:['A','G','C','T','N']};

		var temp = []; //Pass parameters
		var input = []; //Store the gene type in the length of a specific pattern
		var geneAmount = {}; //Store the amount of sepcific pattern
		var part; //Store one pattern in the array
		var i = 0;
		var j = -1;
		var len = 0;
		var offset = 0;
		var amount = 0;

		/*Store a gene sequence of a specified length */
		function get(num){
			if((i+len)<=list.length){
				temp = list.slice(i,i+len); //Cut as specific length
				temp = temp.join(""); //Combine signal items
				input.push(temp); //Put into array
				i++;
			}
		}

		/*Check whether the gene sequence is in the pattern*/
		function search(num){
			j++;
			if(genes[part[j]].indexOf(num)!=-1) //Not exist
				return false;
			else //Exist
				return true;
		}

		/*Show the offset if find and count the amount */
		function select(num, offset, array){
			var arr = num.split(''); //String -> Array
			var ans = arr.filter(search); //Check it
			if(ans.length==0){
				amount++; //Calculate the amount
				testlib.foundMatch(num, offset); //Show the offset
			}
			j = -1;
		}

		/*The main function*/
		function identifyFirst(num){
			len = num.length; //Get the specific length
			part = num.split(''); //String -> Array

			(function myFunction() {
				list.filter(get);
			})();
			(function myFunction() {
				input.filter(select);
			})();

			geneAmount[num]=amount; //Store type and amount in object
			//Reset the parameters
			i = 0;
			input = [];
			amount = 0;
		}

		/*Start the main function*/
		(function myFunction() {
			pattern.map(identifyFirst);
		})();

		testlib.frequencyTable(geneAmount); //Formatting output

	});
});

testlib.setup( 3 );