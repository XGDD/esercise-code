import Java.awt.*;
import Java.applet.Applet;
public class JavaExample extends java.applet.Applet{
    String a = "Hello Java";
    public void paint(Graphics g)
    {
        g.drawString(a, 100, 100);
    }
}