"use strict";

const testlib = require( './testlib.js' );
var list=new Array(); //To store data
var pattern; //To store patterns
var i=0;

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
	list[i]=store;
	i++;
	testlib.on( 'end', function(store){
		var input = []; //Store the gene type in the length of a specific pattern
		var select = []; //Store the amount of patterns
		var gene = {}; //Store the amount of sepcific pattern
		var t = 'X';
		var c = 1;
		
		/*Store a gene sequence of the 2-length */
		function get(num){
			t = t + num;
			input.push(t);
			t = num;
		}

		/*Store a gene sequence of a specified length */
		function set(num){
			if(t===num)
				c++;
			else{
				gene[t] = c;
				t=num;
				c=1;
			}
			gene[t] = c;
		}

		/*Show the offset if find */
		function position(num, index, array){
			if(pattern.indexOf(num)!=-1){
				testlib.foundMatch(num, index);
				select.push(num);
			}
		}

		(function myFunction() {
			list.filter(get);
		})();
		input.shift(); //Move the first one

		(function myFunction() {
			input.filter(position);
		})();
		
		select.sort(); //Sort the 2-grouped-genetypes
		t = 'X';

		(function myFunction() {
			select.filter(set);
		})();
		delete gene.X;//Delete the first one
		testlib.frequencyTable(gene);//Formatting output
	});
});

testlib.setup( 2 );