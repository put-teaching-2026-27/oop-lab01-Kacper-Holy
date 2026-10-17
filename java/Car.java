public class Car {
    private String make;
    private String model;
    private int year;
    private int mileage;

    // TODO: uzupelnij implementacje. Interfejs pozostaje bez zmian.
    public Car(String make, String model, int year) { }
    public String getMake() { return ""; }
    public String getModel() { return ""; }
    public int getYear() { return 0; }
    public int getMileage() { return 0; }
    public int getAge(int currentYear) { return -1; }
    public boolean renameModel(String newModel) { return false; }
    public boolean drive(int distance) { return false; }
}
