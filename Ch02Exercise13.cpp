/*
This program reads the original price, the mark up percentage, and the sales tax rate of an item
then outputs the original price, the percentage of mark up, the selling price, the sales tax rate,
and the final price of the item.
/*

#include <iostream>

using namespace std;

int main() 
{
	double originalPrice;
	double markupPercentage;
	double salesTaxRate;

	cout << "Enter the original price of the item: ";
	cin >> originalPrice;

   	cout << "Enter the percentage markup: ";
    	cin >> markupPercentage;

    	cout << "Enter the sales tax rate: ";
  	cin >> salesTaxRate;

    	// Calculate the selling price after markup
    	double markupAmount = (markupPercentage / 100) * originalPrice;
    	double sellingPrice = originalPrice + markupAmount;

    	// Calculate the sales tax
    	double salesTax = (salesTaxRate / 100) * sellingPrice;

    	// Calculate the final price including sales tax
    	double finalPrice = sellingPrice + salesTax;

    
    	cout << "Original Price of the Item: $" << originalPrice << endl;
    	cout << "Percentage Markup: " << markupPercentage << endl;
    	cout << "Store's Selling Price: $" << sellingPrice << endl;
    	cout << "Sales Tax Rate: " << salesTaxRate << endl;
    	cout << "Sales Tax Amount: $" << salesTax << endl;
    	cout << "Final Price of the Item: $" << finalPrice << endl;

    	return 0;
}
