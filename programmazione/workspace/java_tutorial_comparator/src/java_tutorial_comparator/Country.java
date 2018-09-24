package java_tutorial_comparator;

import java.util.Comparator;

public class Country implements Comparable<Country> {

	static class AreaComparator implements Comparator<Country> {

		@Override
		public int compare(Country o1, Country o2) {
			int result;
			result = o1.getArea() - o2.getArea();
			return result;
		}
	}

	static class PopulationComparator implements Comparator<Country> {

		@Override
		public int compare(Country o1, Country o2) {
			int result;
			result = o1.getPopulation() - o2.getPopulation();
			return result;
		}
	}

	private int area;
	private String name;
	private int population;

	public Country(String name, int area, int population) {
		this.name = name;
		this.area = area;
		this.population = population;
	}

	@Override
	public int compareTo(Country o) {
		int result;
		result = name.compareTo(o.getName());
		return result;
	}

	public int getArea() {
		return area;
	}

	public String getName() {
		return name;
	}

	public int getPopulation() {
		return population;
	}

	public void setArea(int area) {
		this.area = area;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setPopulation(int population) {
		this.population = population;
	}

}
