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
 * store the amount of specific gene sequences
 * show them on the screen.
 * @author Sang Haotian
 */
testlib.on( 'data', function(store){
	list[i]=store;
	i++;
	testlib.on( 'end', function(store){
		var input = []; //Store the gene type in the length of 2
		var t = 'X';
		var c = 1;
		var gene = {};//Store the amount of patterns
		var geneSelected = {};//Store the amount of sepcific pattern

		/*Store a gene sequence of 2-length */
		function get(num){
			t = t + num;
			input.push(t);
			t = num;
		}

		/*Store type and amount in object */
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

		/*Select the pattrern we required */
		function select(num){
			geneSelected[num] = gene[num];
		}

		(function myFunction() {
			list.filter(get);
		})();
		input.shift(); //Move the first one
		input.sort(); //Sort the 2-grouped-genetypes
		t = 'X';

		(function myFunction() {
			input.filter(set);
		})();
		delete gene.X; //Delete the first one

		(function myFunction() {
			pattern.filter(select);
		})();
		testlib.frequencyTable(geneSelected);//Formatting output
	});
});

testlib.setup( 1 );