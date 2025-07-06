package Series;

public class Cubeseries {
    public void printSeries(int n) {
        System.out.println("Cube of Numbers: ");
        for (int i = 1; i <= n; i++) {
            System.out.print((i * i * i) + ", ");
        }
        System.out.println();
    }
}
