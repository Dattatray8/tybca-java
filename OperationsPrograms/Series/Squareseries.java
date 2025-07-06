package Series;

public class Squareseries {
    public void printSeries(int n) {
        System.out.println("Square of Numbers: ");
        for (int i = 1; i <= n; i++) {
            System.out.print((i * i) + ", ");
        }
        System.out.println();
    }
}
