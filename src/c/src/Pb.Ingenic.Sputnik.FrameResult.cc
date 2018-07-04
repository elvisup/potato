#include <string>
#include <frame_result.pb.h>
#include <plate_attribute.pb.h>
#include <mask.pb.h>
#include <inc/Pb.Sputnik.Mask.h>
#include <inc/Pb.Sputnik.FaceAttribute.h>
#include <Pb.Ingenic.Sputnik.FrameResult.h>

using namespace std;
sputnik::pb::FrameResult sputnik_pb_frame_result;

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

int Pb_Ingenic_Sputnik_FrameResult_Data_Deserialize(char *serialize_data)
{
	if (serialize_data == NULL)
		return -1;

	sputnik_pb_frame_result.ParseFromString(serialize_data);  

	return 0;
}

int Pb_Ingenic_Sputnik_FrameResult_Get_Frame_ID(void)
{
	return sputnik_pb_frame_result.frame_id();
}

int Pb_Ingenic_Sputnik_FrameResult_Get_Version(char *version)
{
	if (version == NULL)
		return -1;

	string data;
	data = sputnik_pb_frame_result.version();  
	strcpy(version, data.c_str());

	return 0;
}

int Pb_Ingenic_Sputnik_FrameResult_Get_Items_Cnt(void)
{
	return sputnik_pb_frame_result.items_size();
}

int Pb_Ingenic_Sputnik_FrameResult_Get_Items(int index, items_attr_t *attr)
{
	int i = 0, k = 0, j = 0;
	if((sputnik_pb_frame_result.items_size() - 1) < index )
		return -1;

	sputnik::pb::Item items = sputnik_pb_frame_result.items(index);

	switch(items.type()) {
		case sputnik::pb::ItemType::FACE: attr->items_type = FACE; break;
		case sputnik::pb::ItemType::PLATE: attr->items_type = PLATE; break;
		case sputnik::pb::ItemType::VEHICLE: attr->items_type = VEHICLE; break;
		case sputnik::pb::ItemType::HUMAN: attr->items_type = HUMAN; break;
		default:
			break;
	}

	attr->items_video_channel_id = items.video_channel_id();
	attr->items_frame_id = items.frame_id();
	attr->items_track_id = items.track_id();
	attr->items_track_update = items.track_update();
	attr->items_track_die = items.track_die();
	attr->items_track_show = items.track_show();
	attr->items_track_push = items.track_push();
	attr->items_timestamp_millis = items.timestamp_millis();
	attr->box.valid = items.has_box();
	if (attr->box.valid) {
		//printf("This items has box!\n");
		sputnik::pb::Box box = items.box();
		attr->box.x = box.x();
		attr->box.y = box.y();
		attr->box.w = box.w();
		attr->box.h = box.h();
	}

	//Face
	if (attr->items_type == FACE) {
		sputnik::pb::FaceAttribute face_attr = items.face_attribute();
		attr->face_attr.blur = face_attr.blur();
		attr->face_attr.age = face_attr.age();
		attr->face_attr.gender = face_attr.gender();
		attr->face_attr.pitch = face_attr.pitch();
		attr->face_attr.yaw = face_attr.yaw();
		attr->face_attr.roll = face_attr.roll();
		attr->face_attr.post_filter_score = face_attr.post_filter_score();
		attr->face_attr.minority = face_attr.minority();

		sputnik::pb::FaceLandMark face_landmark = face_attr.landmark();

		//Face Landmark
		string landmark_desc = face_landmark.landmark_description();
		memcpy(attr->face_attr.landmark.landmark_description, landmark_desc.c_str(), landmark_desc.length());
		attr->face_attr.landmark.lefteye_pupil_x = face_landmark.lefteye_pupil_x();
		attr->face_attr.landmark.lefteye_pupil_y = face_landmark.lefteye_pupil_y();
		attr->face_attr.landmark.righteye_pupil_x = face_landmark.righteye_pupil_x();
		attr->face_attr.landmark.righteye_pupil_y = face_landmark.righteye_pupil_y();
		attr->face_attr.landmark.nose_tip_x = face_landmark.nose_tip_x();
		attr->face_attr.landmark.nose_tip_y = face_landmark.nose_tip_y();
		attr->face_attr.landmark.left_mouth_corner_x = face_landmark.left_mouth_corner_x();
		attr->face_attr.landmark.left_mouth_corner_y = face_landmark.left_mouth_corner_y();
		attr->face_attr.landmark.right_mouth_corner_x = face_landmark.right_mouth_corner_x();
		attr->face_attr.landmark.right_mouth_corner_y = face_landmark.right_mouth_corner_y();
		attr->face_attr.landmark.lefteye_right_corner_x = face_landmark.lefteye_right_corner_x();
		attr->face_attr.landmark.lefteye_right_corner_y = face_landmark.lefteye_right_corner_y();
		attr->face_attr.landmark.righteye_left_corner_x = face_landmark.righteye_left_corner_x();
		attr->face_attr.landmark.righteye_left_corner_y = face_landmark.righteye_left_corner_y();
	} else if (attr->items_type == PLATE) {
		sputnik::pb::PlateAttribute plate_attr = items.plate_attribute();
		attr->plate_attribute.roll = plate_attr.roll();
		attr->plate_attribute.quality = plate_attr.quality();
		attr->plate_attribute.plate_style = plate_attr.plate_style();
		attr->plate_attribute.adversary_occlusion = plate_attr.adversary_occlusion();

		//Plate Text Predict
		attr->plate_attribute.plate_numbers_cnt = plate_attr.plate_numbers_size();
		if (attr->plate_attribute.plate_numbers_cnt > MAX_PLATE_NUMBERS) {
			printf("items plate_attribute plate_numbers_cnt is: %d, > %d. set to %d\n", \
				attr->plate_attribute.plate_numbers_cnt, MAX_PLATE_NUMBERS, MAX_PLATE_NUMBERS);
			attr->plate_attribute.plate_numbers_cnt = MAX_PLATE_NUMBERS;
		}

		for (k = 0; k < attr->plate_attribute.plate_numbers_cnt; k++) {
			sputnik::pb::PlateAttribute_PlateTextPredict plate_txt_predict = plate_attr.plate_numbers(k);
			attr->plate_attribute.plate_numbers[k].confidence = plate_txt_predict.confidence();
			string plate_num_text = plate_txt_predict.str_utf8();
			memcpy(attr->plate_attribute.plate_numbers[k].str_utf8, plate_num_text.c_str(), plate_num_text.length());
			attr->plate_attribute.plate_numbers[k].tokens_cnt = plate_txt_predict.tokens_size();
			if (attr->plate_attribute.plate_numbers[k].tokens_cnt > MAX_PLATE_TOKEN_NUMBERS) {
				printf("items plate_attribute plate_numbers tokens_cnt is: %d, > %d. set to %d\n", \
					attr->plate_attribute.plate_numbers[k].tokens_cnt, MAX_PLATE_TOKEN_NUMBERS, \
					MAX_PLATE_TOKEN_NUMBERS);
				attr->plate_attribute.plate_numbers[k].tokens_cnt = MAX_PLATE_TOKEN_NUMBERS;
			}
			for (i = 0; i < attr->plate_attribute.plate_numbers[k].tokens_cnt; i++) {
				sputnik::pb::PlateToken plt_token = plate_txt_predict.tokens(i);
				attr->plate_attribute.plate_numbers[k].tokens[i].confidence = plt_token.confidence();;
				string tokens_text = plt_token.str_utf8();
				memcpy(attr->plate_attribute.plate_numbers[k].tokens[i].str_utf8, tokens_text.c_str(), tokens_text.length());
			}

		}

		//COLOR PREDICT
		attr->plate_attribute.plate_color_predict_cnt = plate_attr.color_predicts_size();
		if (attr->plate_attribute.plate_color_predict_cnt > MAX_PLATE_COLOR_PREDICT_CNT) {
			printf("items plate_attribute plate_color_predict_cnt is: %d, > %d. set to %d\n", \
				attr->plate_attribute.plate_color_predict_cnt, MAX_PLATE_COLOR_PREDICT_CNT, \
				MAX_PLATE_COLOR_PREDICT_CNT);
			attr->plate_attribute.plate_color_predict_cnt = MAX_PLATE_COLOR_PREDICT_CNT;
		}
		for (k = 0; k < attr->plate_attribute.plate_color_predict_cnt; k++) {
			sputnik::pb::PlateAttribute_PlateColorPredict plt_color_predict = plate_attr.color_predicts(k);
			sputnik::pb::PlateColorType pltcolortype = plt_color_predict.color_type();
			switch(plt_color_predict.color_type()) {
				case sputnik::pb::PlateColorType::PLATE_BLUE: attr->plate_attribute.color_predicts[k].color_type = PLATE_BLUE; break;
				case sputnik::pb::PlateColorType::PLATE_YELLOW: attr->plate_attribute.color_predicts[k].color_type = PLATE_YELLOW; break;
				case sputnik::pb::PlateColorType::PLATE_BLACK: attr->plate_attribute.color_predicts[k].color_type = PLATE_BLACK; break;
				case sputnik::pb::PlateColorType::PLATE_WHITE: attr->plate_attribute.color_predicts[k].color_type = PLATE_WHITE; break;
				case sputnik::pb::PlateColorType::PLATE_GREEN: attr->plate_attribute.color_predicts[k].color_type = PLATE_GREEN; break;
				case sputnik::pb::PlateColorType::PLATE_SMALL_NEW_ENERGY: attr->plate_attribute.color_predicts[k].color_type = PLATE_SMALL_NEW_ENERGY; break;
				case sputnik::pb::PlateColorType::PLATE_LARGE_NEW_ENERGY: attr->plate_attribute.color_predicts[k].color_type = PLATE_LARGE_NEW_ENERGY; break;
				case sputnik::pb::PlateColorType::PLATE_ABSENCE: attr->plate_attribute.color_predicts[k].color_type = PLATE_ABSENCE; break;
				default:
					//MAYBE OTHER VALUE??
					attr->plate_attribute.color_predicts[k].color_type = PLATE_ABSENCE;
					break;
			}
			attr->plate_attribute.color_predicts[k].color_confidence = plt_color_predict.color_confidence();
		}

		//FOUR POINT
		sputnik::pb::PlateAttribute_FourPoints four_points = plate_attr.fout_points();
		attr->plate_attribute.fout_points.left_top_x = four_points.left_top_x();
		attr->plate_attribute.fout_points.left_top_y = four_points.left_top_y();
		attr->plate_attribute.fout_points.right_top_x = four_points.right_top_x();
		attr->plate_attribute.fout_points.right_top_y = four_points.right_top_y();
		attr->plate_attribute.fout_points.right_bottom_x = four_points.right_bottom_x();
		attr->plate_attribute.fout_points.right_bottom_y = four_points.right_bottom_y();
		attr->plate_attribute.fout_points.left_bottom_x = four_points.left_bottom_x();
		attr->plate_attribute.fout_points.left_bottom_y = four_points.left_bottom_y();
	} else if (attr->items_type == VEHICLE) {
		sputnik::pb::VehicleAttribute veh_attr = items.vehicle_attribute();
		attr->vehicle_attribute.plate_predicts_cnt = veh_attr.plate_predicts_size();
		if (attr->vehicle_attribute.plate_predicts_cnt > MAX_PLATE_PREDICTS_CNT) {
			printf("items vehicle_attribute plate_predicts_cnt is: %d, > %d. set to %d\n", \
				attr->vehicle_attribute.plate_predicts_cnt, MAX_PLATE_PREDICTS_CNT, \
				MAX_PLATE_PREDICTS_CNT);
			attr->vehicle_attribute.plate_predicts_cnt = MAX_PLATE_PREDICTS_CNT;
		}

		for (k = 0; k < attr->vehicle_attribute.plate_predicts_cnt; k++) {
			sputnik::pb::VehicleAttribute_PlatePredict vecattr_pltpredict = veh_attr.plate_predicts(k);

			//Vehicle Box
			sputnik::pb::Box vehattr_pltprebox = vecattr_pltpredict.plate_relative_box();
			attr->vehicle_attribute.plate_predicts[k].plate_relative_box.x = vehattr_pltprebox.x();
			attr->vehicle_attribute.plate_predicts[k].plate_relative_box.y = vehattr_pltprebox.y();
			attr->vehicle_attribute.plate_predicts[k].plate_relative_box.w = vehattr_pltprebox.w();
			attr->vehicle_attribute.plate_predicts[k].plate_relative_box.h = vehattr_pltprebox.h();

			{//Vehicle Plate Attr
				sputnik::pb::PlateAttribute aehattrpltpdt_pa = vecattr_pltpredict.plate_attribute();
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.roll = aehattrpltpdt_pa.roll();
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.quality = aehattrpltpdt_pa.quality();
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_style = aehattrpltpdt_pa.plate_style();
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.adversary_occlusion = aehattrpltpdt_pa.adversary_occlusion();

				//Plate Text Predict
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers_cnt = aehattrpltpdt_pa.plate_numbers_size();
				if (attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers_cnt > MAX_PLATE_NUMBERS) {
					printf("items vehicle_attribute plate_numbers_cnt is: %d, > %d. set to %d\n", \
						attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers_cnt, MAX_PLATE_NUMBERS, MAX_PLATE_NUMBERS);
					attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers_cnt = MAX_PLATE_NUMBERS;
				}

				for (j = 0; j < attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers_cnt; j++) {
					sputnik::pb::PlateAttribute_PlateTextPredict plate_txt_predict = aehattrpltpdt_pa.plate_numbers(j);
					attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers[j].confidence = plate_txt_predict.confidence();
					string plate_num_text = plate_txt_predict.str_utf8();
					memcpy(attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers[j].str_utf8, \
							plate_num_text.c_str(), plate_num_text.length());
					attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers[j].tokens_cnt = plate_txt_predict.tokens_size();
					if (attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers[j].tokens_cnt > MAX_PLATE_TOKEN_NUMBERS) {
						printf("items plate_attribute plate_numbers tokens_cnt is: %d, > %d. set to %d\n", \
								attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers[j].tokens_cnt, \
								MAX_PLATE_TOKEN_NUMBERS, MAX_PLATE_TOKEN_NUMBERS);
						attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers[j].tokens_cnt = MAX_PLATE_TOKEN_NUMBERS;
					}
					for (i = 0; i < attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers[j].tokens_cnt; i++) {
						sputnik::pb::PlateToken plt_token = plate_txt_predict.tokens(i);
						attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers[j].tokens[i].confidence = plt_token.confidence();;
						string tokens_text = plt_token.str_utf8();
						memcpy(attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_numbers[j].tokens[i].str_utf8, \
								tokens_text.c_str(), tokens_text.length());
					}
				}

				//COLOR PREDICT
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_color_predict_cnt = aehattrpltpdt_pa.color_predicts_size();
				if (attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_color_predict_cnt > MAX_PLATE_COLOR_PREDICT_CNT) {
					printf("items plate_attribute plate_color_predict_cnt is: %d, > %d. set to %d\n", \
							attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_color_predict_cnt, MAX_PLATE_COLOR_PREDICT_CNT, \
							MAX_PLATE_COLOR_PREDICT_CNT);
					attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_color_predict_cnt = MAX_PLATE_COLOR_PREDICT_CNT;
				}
				for (j = 0; j < attr->vehicle_attribute.plate_predicts[k].plate_attribute.plate_color_predict_cnt; j++) {
					sputnik::pb::PlateAttribute_PlateColorPredict plt_color_predict = aehattrpltpdt_pa.color_predicts(j);
					sputnik::pb::PlateColorType pltcolortype = plt_color_predict.color_type();
					switch(plt_color_predict.color_type()) {
						case sputnik::pb::PlateColorType::PLATE_BLUE:
							attr->vehicle_attribute.plate_predicts[k].plate_attribute.color_predicts[j].color_type = PLATE_BLUE; break;
						case sputnik::pb::PlateColorType::PLATE_YELLOW:
							attr->vehicle_attribute.plate_predicts[k].plate_attribute.color_predicts[j].color_type = PLATE_YELLOW; break;
						case sputnik::pb::PlateColorType::PLATE_BLACK:
							attr->vehicle_attribute.plate_predicts[k].plate_attribute.color_predicts[j].color_type = PLATE_BLACK; break;
						case sputnik::pb::PlateColorType::PLATE_WHITE:
							attr->vehicle_attribute.plate_predicts[k].plate_attribute.color_predicts[j].color_type = PLATE_WHITE; break;
						case sputnik::pb::PlateColorType::PLATE_GREEN:
							attr->vehicle_attribute.plate_predicts[k].plate_attribute.color_predicts[j].color_type = PLATE_GREEN; break;
						case sputnik::pb::PlateColorType::PLATE_SMALL_NEW_ENERGY:
							attr->vehicle_attribute.plate_predicts[k].plate_attribute.color_predicts[j].color_type = PLATE_SMALL_NEW_ENERGY; break;
						case sputnik::pb::PlateColorType::PLATE_LARGE_NEW_ENERGY:
							attr->vehicle_attribute.plate_predicts[k].plate_attribute.color_predicts[j].color_type = PLATE_LARGE_NEW_ENERGY; break;
						case sputnik::pb::PlateColorType::PLATE_ABSENCE:
							attr->vehicle_attribute.plate_predicts[k].plate_attribute.color_predicts[j].color_type = PLATE_ABSENCE; break;
						default:
							//MAYBE OTHER VALUE??
							attr->vehicle_attribute.plate_predicts[k].plate_attribute.color_predicts[j].color_type = PLATE_ABSENCE;
							break;
					}
					attr->vehicle_attribute.plate_predicts[k].plate_attribute.color_predicts[j].color_confidence = plt_color_predict.color_confidence();
				}

				//FOUR POINT
				sputnik::pb::PlateAttribute_FourPoints four_points = aehattrpltpdt_pa.fout_points();
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.fout_points.left_top_x = four_points.left_top_x();
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.fout_points.left_top_y = four_points.left_top_y();
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.fout_points.right_top_x = four_points.right_top_x();
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.fout_points.right_top_y = four_points.right_top_y();
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.fout_points.right_bottom_x = four_points.right_bottom_x();
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.fout_points.right_bottom_y = four_points.right_bottom_y();
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.fout_points.left_bottom_x = four_points.left_bottom_x();
				attr->vehicle_attribute.plate_predicts[k].plate_attribute.fout_points.left_bottom_y = four_points.left_bottom_y();
			}
		}

		attr->vehicle_attribute.type_predicts_cnt = veh_attr.type_predicts_size();
		if (attr->vehicle_attribute.type_predicts_cnt > MAX_TYPE_PREDICTS_CNT) {
			printf("items vehicle_attribute type_predicts_cnt is: %d, > %d. set to %d\n", \
				attr->vehicle_attribute.type_predicts_cnt, MAX_TYPE_PREDICTS_CNT, \
				MAX_TYPE_PREDICTS_CNT);
			attr->vehicle_attribute.type_predicts_cnt = MAX_TYPE_PREDICTS_CNT;
		}
		for (k = 0; k < attr->vehicle_attribute.type_predicts_cnt; k++) {
			sputnik::pb::VehicleAttribute_VehicleTypePredict cehtypepdt = veh_attr.type_predicts(k);
			attr->vehicle_attribute.type_predicts[k].type_confidence = cehtypepdt.type_confidence();
			switch(cehtypepdt.vehicle_type()) {
				case sputnik::pb::VehicleType::CAR:
					attr->vehicle_attribute.type_predicts[k].vehicle_type = CAR; break;
				case sputnik::pb::VehicleType::SUV:
					attr->vehicle_attribute.type_predicts[k].vehicle_type = SUV; break;
				case sputnik::pb::VehicleType::MICROBUS:
					attr->vehicle_attribute.type_predicts[k].vehicle_type = MICROBUS; break;
				case sputnik::pb::VehicleType::MINIBUS:
					attr->vehicle_attribute.type_predicts[k].vehicle_type = MINIBUS; break;
				case sputnik::pb::VehicleType::BUS:
					attr->vehicle_attribute.type_predicts[k].vehicle_type = BUS; break;
				case sputnik::pb::VehicleType::PICKUP:
					attr->vehicle_attribute.type_predicts[k].vehicle_type = PICKUP; break;
				case sputnik::pb::VehicleType::TRUCK:
					attr->vehicle_attribute.type_predicts[k].vehicle_type = TRUCK; break;
				default:
					attr->vehicle_attribute.type_predicts[k].vehicle_type = CAR; break;
					break;
			}
		}

		attr->vehicle_attribute.color_predicts_cnt = veh_attr.color_predicts_size();
		if (attr->vehicle_attribute.color_predicts_cnt > MAX_COLOR_PREDICTS_CNT) {
			printf("items vehicle_attribute color_predicts_cnt is: %d, > %d. set to %d\n", \
				attr->vehicle_attribute.color_predicts_cnt, MAX_COLOR_PREDICTS_CNT, \
				MAX_COLOR_PREDICTS_CNT);
			attr->vehicle_attribute.color_predicts_cnt = MAX_COLOR_PREDICTS_CNT;
		}
		for (k = 0; k < attr->vehicle_attribute.color_predicts_cnt; k++) {
			sputnik::pb::VehicleAttribute_VehicleColorPredict vehcolpdt = veh_attr.color_predicts(k);
			attr->vehicle_attribute.color_predicts[k].color_confidence = vehcolpdt.color_confidence();
			switch(vehcolpdt.vehicle_color()) {
				case sputnik::pb::VehicleColor::BLUE:
					attr->vehicle_attribute.color_predicts[k].vehicle_color = BLUE; break;
				case sputnik::pb::VehicleColor::YELLOW:
					attr->vehicle_attribute.color_predicts[k].vehicle_color = YELLOW; break;
				case sputnik::pb::VehicleColor::BLACK:
					attr->vehicle_attribute.color_predicts[k].vehicle_color = BLACK; break;
				case sputnik::pb::VehicleColor::WHITE:
					attr->vehicle_attribute.color_predicts[k].vehicle_color = WHITE; break;
				case sputnik::pb::VehicleColor::GREEN:
					attr->vehicle_attribute.color_predicts[k].vehicle_color = GREEN; break;
				case sputnik::pb::VehicleColor::RED:
					attr->vehicle_attribute.color_predicts[k].vehicle_color = RED; break;
				case sputnik::pb::VehicleColor::GRAY:
					attr->vehicle_attribute.color_predicts[k].vehicle_color = GRAY; break;
				case sputnik::pb::VehicleColor::PURPLE:
					attr->vehicle_attribute.color_predicts[k].vehicle_color = PURPLE; break;
				case sputnik::pb::VehicleColor::PINK:
					attr->vehicle_attribute.color_predicts[k].vehicle_color = PINK; break;
				case sputnik::pb::VehicleColor::BROWN:
					attr->vehicle_attribute.color_predicts[k].vehicle_color = BROWN; break;
				case sputnik::pb::VehicleColor::CYAN:
					attr->vehicle_attribute.color_predicts[k].vehicle_color = CYAN; break;
				case sputnik::pb::VehicleColor::COLORFUL:
					attr->vehicle_attribute.color_predicts[k].vehicle_color = COLORFUL; break;
				default:
					attr->vehicle_attribute.color_predicts[k].vehicle_color = COLORFUL; break;
					break;
			}
		}

		string trdmk_utf8 = veh_attr.trademark_utf8();
		memcpy(attr->vehicle_attribute.trademark_utf8, trdmk_utf8.c_str(), trdmk_utf8.length());
		attr->vehicle_attribute.trademark_utf8_confidence = veh_attr.trademark_utf8_confidence();
		attr->vehicle_attribute.vehicle_plateless = veh_attr.vehicle_plateless();
		attr->vehicle_attribute.vehicle_moving = veh_attr.vehicle_moving();

		switch(veh_attr.move_direction()) {
			case sputnik::pb::Direction::UP:
				attr->vehicle_attribute.move_direction = UP; break;
			case sputnik::pb::Direction::DOWN:
				attr->vehicle_attribute.move_direction = DOWN; break;
			case sputnik::pb::Direction::LEFT:
				attr->vehicle_attribute.move_direction = LEFT; break;
			case sputnik::pb::Direction::RIGHT:
				attr->vehicle_attribute.move_direction = RIGHT; break;
			default:
				attr->vehicle_attribute.move_direction = UP; break;
				break;
		}
		attr->vehicle_attribute.move_direction_confidence = veh_attr.move_direction_confidence();

		switch(veh_attr.pointing_direction()) {
			case sputnik::pb::Direction::UP:
				attr->vehicle_attribute.pointing_direction = UP; break;
			case sputnik::pb::Direction::DOWN:
				attr->vehicle_attribute.pointing_direction = DOWN; break;
			case sputnik::pb::Direction::LEFT:
				attr->vehicle_attribute.pointing_direction = LEFT; break;
			case sputnik::pb::Direction::RIGHT:
				attr->vehicle_attribute.pointing_direction = RIGHT; break;
			default:
				attr->vehicle_attribute.pointing_direction = UP; break;
				break;
		}
		attr->vehicle_attribute.pointing_direction_confidence = veh_attr.pointing_direction_confidence();

		//Facing
		switch(veh_attr.vehicle_facing()) {
			case sputnik::pb::Facing::FRONT:
				attr->vehicle_attribute.vehicle_facing = FRONT; break;
			case sputnik::pb::Facing::BACK:
				attr->vehicle_attribute.vehicle_facing = BACK; break;
			case sputnik::pb::Facing::SIDE:
				attr->vehicle_attribute.vehicle_facing = SIDE; break;
			default:
				attr->vehicle_attribute.vehicle_facing = FRONT; break;
				break;
		}
		attr->vehicle_attribute.vehicle_facing_confidence = veh_attr.vehicle_facing_confidence();
	} else if (attr->items_type == HUMAN) {
		sputnik::pb::HumanAttribute human_attr = items.human_attribute();
		attr->human_attribute.gender = human_attr.gender();
		attr->human_attribute.age = human_attr.age();
		attr->human_attribute.backpack = human_attr.backpack();
		attr->human_attribute.human_move = human_attr.human_move();
		switch(human_attr.move_direction()) {
			case sputnik::pb::Direction::UP:
				attr->human_attribute.move_direction = UP; break;
			case sputnik::pb::Direction::DOWN:
				attr->human_attribute.move_direction = DOWN; break;
			case sputnik::pb::Direction::LEFT:
				attr->human_attribute.move_direction = LEFT; break;
			case sputnik::pb::Direction::RIGHT:
				attr->human_attribute.move_direction = RIGHT; break;
			default:
				attr->human_attribute.move_direction = UP; break;
				break;
		}
		attr->human_attribute.ride_bike = human_attr.ride_bike();
		attr->human_attribute.ride_motorbike = human_attr.ride_motorbike();
		attr->human_attribute.human_face_visible = human_attr.human_face_visible();
		switch(human_attr.human_facing()) {
			case sputnik::pb::Facing::FRONT:
				attr->human_attribute.human_facing = FRONT; break;
			case sputnik::pb::Facing::BACK:
				attr->human_attribute.human_facing = BACK; break;
			case sputnik::pb::Facing::SIDE:
				attr->human_attribute.human_facing = SIDE; break;
			default:
				attr->human_attribute.human_facing = FRONT; break;
				break;
		}
		attr->human_attribute.human_facing_confidence = human_attr.human_facing_confidence();
	} else {
		printf("ERROR: items type error!\n");
	}

	//Image
	sputnik::pb::Image* image = items.mutable_item_image();
	attr->item_image.h = image->h();
	attr->item_image.w = image->w();
	attr->item_image.c = image->c();

	string str_data = image->data();
	memcpy(attr->item_image.data, str_data.c_str(), str_data.length());

	//Mask
	sputnik::pb::Mask* mask = items.mutable_mask();
	attr->mask.x = mask->x();
	attr->mask.y = mask->y();
	attr->mask.w = mask->w();
	attr->mask.h = mask->h();
	attr->mask.resolution = mask->resolution();

	attr->mask.pix_confidence_cnt = mask->pix_confidence_size();
	if (attr->mask.pix_confidence_cnt > MAX_PIX_CONFIDENCE_CNT) {
		printf("items mask pix_confidence_cnt is: %d, > %d. set to %d\n", \
			attr->mask.pix_confidence_cnt, MAX_PIX_CONFIDENCE_CNT, MAX_PIX_CONFIDENCE_CNT);
		attr->mask.pix_confidence_cnt = MAX_PIX_CONFIDENCE_CNT;
	}

	for (k = 0; k < attr->mask.pix_confidence_cnt; k++) {
		attr->mask.pix_confidence[k] = mask->pix_confidence(k);
	}

	//TracePoint
	attr->trace_point_cnt = items.trace_size();
	if (attr->trace_point_cnt > MAX_TRACEPOINT_CNT) {
		printf("items mask trace_point_cnt is: %d, > %d. set to %d\n", \
			attr->trace_point_cnt, MAX_TRACEPOINT_CNT, MAX_TRACEPOINT_CNT);
		attr->trace_point_cnt = MAX_TRACEPOINT_CNT;
	}

	for (k = 0; k < attr->trace_point_cnt; k++) {
		sputnik::pb::TracePoint tracepoint = items.trace(k);
		attr->trace[k].x = tracepoint.x();
		attr->trace[k].y = tracepoint.y();
		attr->trace[k].timestamp_millis = tracepoint.timestamp_millis();
	}

	//Item_text_utf8
	string item_txt_utf8 = items.item_text_utf8();
	memcpy(attr->item_text_utf8, item_txt_utf8.c_str(), item_txt_utf8.length());

	//Blob
	string items_blob = items.blob();
	attr->blob_size = items_blob.length();
	memcpy(attr->blob, items_blob.c_str(), items_blob.length());

	return 0;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
