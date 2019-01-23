// Created by Johnny Li.	Section: 149A 

/* This program was created to meet the requirements of Project 1: Fluffy Swarm.
 The program calculates the distance between two drones in the xy-coordinates and 3D space from
 inputed coordinates for the Department of Defense to find lost pets. The program then relay the distance 
 between the two drone and tells the pilot to: move the drones farther apart if they are less than 1 foot 
 apart, move the drones closer together if they are over 500 feet apart, and states that no actions are 
 required if the distance between the two drones is optimally between 1 and 500 feet apart.
 */

import java.util.Scanner; 

public class DronesLocation {
	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);

		System.out.println ("Please enter the x coordinate of Drone 1: ");
		double drone1X= input.nextDouble();	// Drone 1 x-coordinate.

		System.out.println ("Please enter the y coordinate of Drone 1: ");
		double drone1Y= input.nextDouble();	// Drone 1 y-coordinate.

		System.out.println ("Please enter the altitude of Drone 1: ");
		double drone1Z= input.nextDouble();	// Drone 1 altitude.

		System.out.println ("Please enter the x coordinate of Drone 2: ");
		double drone2X= input.nextDouble();	// Drone 2 x-coordinate.

		System.out.println ("Please enter the y coordinate of Drone 2: ");
		double drone2Y= input.nextDouble();	// Drone 2 y-coordinate.

		System.out.println ("Please enter the altitude of Drone 2: ");
		double drone2Z= input.nextDouble();	// Drone 2 altitude.

		input.close();   

		double distanceXY = Math.sqrt(Math.pow(drone2X-drone1X,2) + Math.pow(drone2Y-drone1Y,2));
		/*The distance between the two drones in the (x,y) coordinate. 
		Distance Formula = sqrt((x2−x1)^2+(y2−y1)^2)*/

		if (500 >= distanceXY && distanceXY >= 1) {
			System.out.println ("The two drones are " + distanceXY + " feet apart in (x,y) coordinates. "
			+ "They do not need to move farther apart or closer in (x,y).");
		}
		/*Statement telling pilot that there is no need to move the drones. 
		(Distances between the drones is less than 500 feet apart and greater than 1 foot together on xy-coordinate.)*/
		else if (distanceXY > 500) {
			System.out.println ("The two drones are " + distanceXY + " feet apart in (x,y) coordinates. " 
			+ "They need to move closer together in (x,y).");
		/*Statement telling pilot to move the drones closer together because they are too far apart. 
		(Distances between the drones is greater than 500 feet on xy-coordinate.)*/
		}
		else if (1 > distanceXY){
			System.out.println ("The two drones are " + distanceXY + " feet apart in (x,y) coordinates. " 
			+ "They need to move farther apart in (x,y).");
		/*Statement telling pilot to move the drones farther apart because camera views overlap. 
		(Distances between the drones is less than 1 foot on xy-coordinate.)*/
		}
		
		double distanceXYZ = Math.sqrt(Math.pow(drone2X-drone1X,2) + Math.pow(drone2Y-drone1Y,2) + Math.pow(drone2Z-drone1Z,2));
		/*The distance between the two drones in the 3D space. 
		Distance Formula = sqrt((x2−x1)^2+(y2−y1)^2+(z2-z1)^2)*/

		if (500 >= distanceXYZ && distanceXYZ >= 1) {
			System.out.println ("The two drones are " + distanceXYZ + " feet apart in 3D space. "
			+ "They do not need to move farther apart or closer.");
		}
		/*Statement telling pilot that there is no need to move the drones. 
		(Distances between the drones is less than 500 feet apart and greater than 1 foot together in 3D space.)*/
		else if (distanceXYZ > 500) {
			System.out.println ("The two drones are " + distanceXYZ + " feet apart in 3D space. "
			+ "They need to move closer together.");
		/*Statement telling pilot to move the drones closer together because they are too far apart. 
	  	(Distances between the drones is greater than 500 feet in 3D space.)*/
		}
		else if (1 > distanceXYZ){
			System.out.println ("The two drones are " + distanceXYZ + " feet apart in 3D space. " 
			+ "They need to move farther apart.");
		/*Statement telling pilot to move the drones farther apart because they are too close together. 
		(Distances between the drones is less than 1 foot in 3D space.)*/
		}
	}
}