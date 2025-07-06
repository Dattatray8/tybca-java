import Series.Cubeseries;
import Series.Squareseries;
import java.util.Scanner;

public class SeriesMain{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of n: ");
        int n = sc.nextInt();

        Cubeseries c = new Cubeseries();
        Squareseries s = new Squareseries();

        c.printSeries(n);
        s.printSeries(n);
    }
}