package Java;
// Inheritance in Java (Core OOP Pillar)

public class Four {

    public static void main(String[] args) {
        System.out.println("--- 1. Single Inheritance (Car extends Vehicle) ---");
        Car myCar = new Car("Toyota", 2024, 4);
        myCar.start();          // Overridden method in Car
        myCar.honk();           // Inherited method from Vehicle
        myCar.displayCarInfo(); // Car's own specific method

        System.out.println("\n--- 2. Multilevel Inheritance (ElectricCar -> Car -> Vehicle) ---");
        ElectricCar tesla = new ElectricCar("Tesla", 2024, 4, 100);
        tesla.start();          // Overridden in ElectricCar
        tesla.charge();         // ElectricCar's own method
        tesla.honk();           // Inherited all the way from Vehicle!

        System.out.println("\n--- 3. Hierarchical Inheritance (Bike extends Vehicle) ---");
        Bike myBike = new Bike("Yamaha", 2023, true);
        myBike.start();         // Overridden in Bike
        myBike.honk();          // Inherited from Vehicle

        System.out.println("\n--- 4. Polymorphism / Upcasting ---");
        // Parent reference holding a Child instance
        Vehicle v = new Car("Honda", 2022, 4);
        v.start(); // Calls Car's start() at runtime (Runtime Polymorphism / Dynamic Method Dispatch)
        // v.displayCarInfo(); // COMPILE ERROR: Vehicle reference cannot access Car-specific methods
    }
}

// Superclass (Parent)
class Vehicle {
    protected String brand;
    protected int year;

    // Parent Constructor
    public Vehicle(String brand, int year) {
        this.brand = brand;
        this.year = year;
        System.out.println("[Vehicle Constructor] Initialized: " + brand);
    }

    public void start() {
        System.out.println(brand + " engine started.");
    }

    public void honk() {
        System.out.println(brand + " says: Beep beep!");
    }
}

// Subclass (Child) - Single Inheritance
class Car extends Vehicle {
    private int doors;

    // Child Constructor
    public Car(String brand, int year, int doors) {
        // super(...) calls the parent constructor
        // MUST be the very first statement
        super(brand, year);
        this.doors = doors;
        System.out.println("[Car Constructor] Doors: " + doors);
    }

    // Method Overriding: Child customizes parent's behavior
    @Override
    public void start() {
        super.start(); // Optionally call parent method logic using 'super'
        System.out.println("Car is ready to drive.");
    }

    public void displayCarInfo() {
        // Inherited protected fields (brand, year) are directly accessible
        System.out.println("Car Info -> Brand: " + brand + " | Year: " + year + " | Doors: " + doors);
    }
}

// Grandchild Class - Multilevel Inheritance (ElectricCar -> Car -> Vehicle)
class ElectricCar extends Car {
    private int batteryCapacity;

    public ElectricCar(String brand, int year, int doors, int batteryCapacity) {
        super(brand, year, doors); // Calls Car's constructor
        this.batteryCapacity = batteryCapacity;
        System.out.println("[ElectricCar Constructor] Battery: " + batteryCapacity + " kWh");
    }

    @Override
    public void start() {
        System.out.println(brand + " electric motor powered on silently.");
    }

    public void charge() {
        System.out.println(brand + " is charging battery (" + batteryCapacity + " kWh).");
    }
}

// Sibling Subclass - Hierarchical Inheritance (Bike -> Vehicle)
class Bike extends Vehicle {
    private boolean hasGear;

    public Bike(String brand, int year, boolean hasGear) {
        super(brand, year);
        this.hasGear = hasGear;
        System.out.println("[Bike Constructor] Has gear: " + hasGear);
    }

    @Override
    public void start() {
        System.out.println(brand + " bike kick-started.");
    }
}
