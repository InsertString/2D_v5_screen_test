#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


//STATIC PROTOTYPES//
static lv_res_t btn_rel_action(lv_obj_t * btn);




int i;
std::string i_text;




void opcontrol() {

	/********************
  * CREATE A SCREEN
  *******************/
  /* Create a new screen and load it
   * Screen can be created from any type object type*/
	lv_obj_t * scr = lv_page_create(NULL, NULL);
  lv_scr_load(scr);

	//create label
	lv_obj_t * label = lv_label_create(scr, NULL); /*First parameters (scr) is the parent*/
  lv_label_set_text(label, "Hello World");  /*Set the text*/
  lv_obj_set_x(label, 50);                        /*Set the x coordinate*/

	//create button
	lv_obj_t * btn1 = lv_btn_create(lv_scr_act(), NULL);
	lv_btn_set_action(btn1, LV_BTN_ACTION_CLICK, btn_rel_action); /*Set function to be called when the button is released*/
  lv_obj_align(btn1, label, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);  /*Align below the label*/
	label = lv_label_create(btn1, NULL);
	lv_label_set_text(label, ". . .");

	while (true) {




		pros::delay(20);
	}
}



/**
 * Called when a button is released
 * @param btn pointer to the released button
 * @return LV_RES_OK because the object is not deleted in this function
 */
static  lv_res_t btn_rel_action(lv_obj_t * btn)
{
		i++;

    return LV_RES_OK;
}
