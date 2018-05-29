/*
 * auxiliary.cpp
 *
 *  Created on: Aug 14, 2017
 *      Author: hpcochep
 */

using namespace std;

#include "auxiliary.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

string get_time_as_string(struct tm * time) {

	string year_4digs, mon_2digs, day_2digs, hour_2digs, minute_2digs,
			sec_2digs;
	stringstream sstemp, sstemp1, sstemp2, sstemp3, sstemp4;

	sstemp << setw(2) << setfill('0') << time->tm_mday;
	day_2digs = sstemp.str();
	sstemp1 << setw(2) << setfill('0') << (time->tm_mon + 1);
	mon_2digs = sstemp1.str();
	year_4digs = std::to_string(time->tm_year + 1900);

	sstemp2 << setw(2) << setfill('0') << (time->tm_hour);
	hour_2digs = sstemp2.str();
	sstemp3 << setw(2) << setfill('0') << (time->tm_min);
	minute_2digs = sstemp3.str();
	sstemp4 << setw(2) << setfill('0') << (time->tm_sec);
	sec_2digs = sstemp4.str();

	return year_4digs + "-" + mon_2digs + "-" + day_2digs + "T" + hour_2digs
			+ ":" + minute_2digs + ":" + sec_2digs;

}

string get_time_with_displacement(struct tm * initial_time, int disp_in_secs) {

	struct tm new_time = *initial_time;

	new_time.tm_sec += disp_in_secs; // add displacement (in seconds) to the timestamp
	mktime(&new_time); // normalize the timestamp

	return get_time_as_string(&new_time);

}

string gen_file_name() {
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);

	string year_4digs, mon_2digs, day_2digs, hour_2digs, minute_2digs,
			sec_2digs;
	stringstream sstemp, sstemp1, sstemp2, sstemp3, sstemp4;

	/*sstemp << setw(2) << setfill('0') << now->tm_mday;
	 day_2digs = sstemp.str();
	 sstemp1 << setw(2) << setfill('0') << (now->tm_mon + 1);
	 mon_2digs = sstemp1.str();
	 year_4digs = std::to_string(now->tm_year + 1900);
	 */
	sstemp2 << setw(2) << setfill('0') << (now->tm_hour);
	hour_2digs = sstemp2.str();
	sstemp3 << setw(2) << setfill('0') << (now->tm_min);
	minute_2digs = sstemp3.str();
	sstemp4 << setw(2) << setfill('0') << (now->tm_sec);
	sec_2digs = sstemp4.str();

	/*return year_4digs + "-" + mon_2digs + "-" + day_2digs + ":" + hour_2digs
	 + "-" + minute_2digs + "-" + sec_2digs;;
	 */

	return hour_2digs + "-" + minute_2digs + "-" + sec_2digs;
}

void create_output_file(string name_prefix, fstream& f) {
	string filename = name_prefix + gen_file_name() + ".csv";
	f.open(filename, ios::out);
}
