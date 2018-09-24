package java_tutorial_comparator;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MainClass {

	public static void main(String[] args) {

		List<Country> myCountryList = new ArrayList<Country>();

		Country germany = new Country("Germany", 357021, 81305856);
		Country french = new Country("French", 547030, 65630692);
		Country unitedKingdom = new Country("United Kingdom", 244820, 63047162);
		Country italy = new Country("Italy", 301230, 61261254);
		Country spain = new Country("Spain", 504851, 47042984);

		myCountryList.add(germany);
		myCountryList.add(french);
		myCountryList.add(unitedKingdom);
		myCountryList.add(italy);
		myCountryList.add(spain);

		// FIRST SECTION

		System.out.println("\nSORTED LIST BY NAME:");
		Collections.sort(myCountryList);

		for (Country item : myCountryList) {
			System.out.println(item.getName());
		}

		// SECOND SECTION

		System.out.println("\nSORTED LIST BY AREA:");
		Collections.sort(myCountryList, new Country.AreaComparator());

		for (Country item : myCountryList) {
			System.out.println(item.getName());
		}

		// THIRD SECTION

		System.out.println("\nSORTED LIST BY POPULATION IN DESCENDING ORDER:");
		Collections.sort(myCountryList, Collections.reverseOrder(new Country.PopulationComparator()));

		for (Country item : myCountryList) {
			System.out.println(item.getName());
		}

		// FOURTH SECTION

		System.out.println("\nSORTED LIST BY NAME IN DESCENDING ORDER:");
		Collections.sort(myCountryList, Collections.reverseOrder());

		for (Country item : myCountryList) {
			System.out.println(item.getName());
		}

	}
}
