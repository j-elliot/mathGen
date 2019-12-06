
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Random;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class worksheetGen
{
    public static void main(String args[]) throws IOException, InterruptedException
    {

        String fileSeparator = System.getProperty("file.separator");
        Random random = new Random();
        int max = 1000;
        int min = 10;
        int rows = 3;
        int cols = 5;
        int spread = max - min;

        //relative path
        String relativePath = "ws.tex";
        File file = new File(relativePath);
        if(file.createNewFile()){
            System.out.println(relativePath+" File Created in Project root directory");
        }else System.out.println("File "+relativePath+" already exists in the project root directory");

        FileWriter write = new FileWriter(relativePath, false);
        PrintWriter print_line = new PrintWriter(write);

        String columnMarks = "";
        for(int j = 0; j < cols; j++)
        {

          columnMarks = columnMarks.concat("X");

          System.out.println(columnMarks);

        }

        print_line.println("\t\\documentclass[20pt]{scrartcl}\n\t\\usepackage{tabu,mathtools}\n\t\\setlength\\parindent{0pt}\n\t\\tabulinesep=_50pt\n\t\\begin{document}\n\t\\begin{center}\n\t\t\\LARGE Worksheet\n\t\\end{center}\n\t\\begin{tabu} to \\linewidth {" + columnMarks + "}");

        for(int i = 0; i < rows; i++)
        {
          for(int j = 0; j < cols; j++)
          {

            int val1 = new Random().nextInt(spread + 1) + min;
            int val2 = new Random().nextInt(spread + 1) + min;

            print_line.println("\t\t$\\begin{array}{r}\n\t\t\t" + val1 + " \\\\\n\t\t\t+" + val2 + " \\\\\n\t\t\t\\hline\n\t\t\t\\end{array}$\n\t\t");

            if(j < 4)
            {

              print_line.println("\t\t&");

            }else
            {

              print_line.println("");

            }

          }

          if(i < 2)
          {

            print_line.println("\t\t\\\\");

          }

        }

        print_line.println("\t\t\\end{tabu}\n\n\t\t\\end{document}");

        print_line.close();

        try {


          String command = "pdflatex ws.tex";

          Process process = Runtime.getRuntime().exec(command);

          BufferedReader reader =
                  new BufferedReader(new InputStreamReader(process.getInputStream()));

          String line;
          while ((line = reader.readLine()) != null) {
              System.out.println(line);
          }

          int exitCode = process.waitFor();
          System.out.println("\nExited with error code : " + exitCode);

        } catch (IOException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
}
