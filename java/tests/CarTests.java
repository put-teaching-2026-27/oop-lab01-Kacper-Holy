public class CarTests {
    private static int failed = 0;
    private static void check(boolean condition, String name) {
        System.out.println((condition ? "PASS: " : "FAIL: ") + name);
        if (!condition) ++failed;
    }
    public static void main(String[] args) {
        Car a = new Car("Toyota", "Corolla", 2020);
        Car b = new Car("Honda", "Civic", 2022);
        Car c = new Car("Ford", "Focus", 2021);
        check("Toyota".equals(a.getMake()), "constructor make");
        check("Corolla".equals(a.getModel()), "constructor model");
        check(a.getYear() == 2020, "constructor year");
        check(a.getMileage() == 0, "initial mileage");
        check(a.getAge(2026) == 6, "age normal");
        check(a.getAge(2020) == 0, "age zero");
        check(a.getAge(2019) == -1, "age invalid");
        check(a.drive(120), "drive positive");
        check(a.getMileage() == 120, "mileage after drive");
        check(a.drive(30), "drive again");
        check(a.getMileage() == 150, "mileage accumulates");
        check(!a.drive(0), "drive zero rejected");
        check(!a.drive(-50), "drive negative rejected");
        check(a.getMileage() == 150, "rejected drive preserves state");
        check(b.getMileage() == 0, "independent mileage");
        check(a.renameModel("Touring"), "rename accepted");
        check("Touring".equals(a.getModel()), "renamed model");
        check(!a.renameModel(""), "empty rejected");
        check(!a.renameModel(" \t\r\n"), "whitespace rejected");
        check("Touring".equals(a.getModel()), "rejected rename preserves state");
        check("Civic".equals(b.getModel()), "independent model");
        check("Toyota".equals(a.getMake()), "immutable make");
        check(a.getYear() == 2020, "immutable year");
        check(c.drive(1000000), "drive upper bound");
        check(!c.drive(1), "reject overflow of domain");
        check(c.getMileage() == 1000000, "upper bound preserves state");
        check(!a.renameModel(null), "null rejected");
        check("Touring".equals(a.getModel()), "null preserves state");
        System.out.println("Failed: " + failed);
        if (failed != 0) System.exit(1);
    }
}
