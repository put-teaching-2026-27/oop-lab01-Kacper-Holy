public class Main {
    public static void main(String[] args) {
        Car first = new Car("Toyota", "Corolla", 2020);
        Car second = new Car("Honda", "Civic", 2022);
        first.drive(120);
        first.renameModel("Corolla Touring");
        System.out.println(first.getMake() + " " + first.getModel()
            + " | year=" + first.getYear() + " | age=" + first.getAge(2026)
            + " | mileage=" + first.getMileage());
        System.out.println(second.getMake() + " " + second.getModel()
            + " | mileage=" + second.getMileage());
        // TODO: pokaz odrzucona operacje i niezmieniony stan obiektu.
    }
}

