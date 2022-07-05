#include "Score.h"

Score::Score(double s1, double s2, double s3, double s4) :study_Score(s1), daily_Score(s2), per_Score(s3), inter_Score(s4)
{
	sum_Score = study_Score * 0.6 + daily_Score * 0.24 + per_Score + inter_Score * 0.14;
}
double Score::get_sum_Score()
{
	return sum_Score;
}
double Score::get_study_Score()
{
	return study_Score;
}
double Score::get_daily_Score()
{
	return daily_Score;
}
double Score::get_per_Score()
{
	return per_Score;
}
double Score::get_inter_Score()
{
	return inter_Score;
}

void Score::set_sum_Score(double score)
{
	sum_Score = score;
}

void Score::set_study_Score(double score)
{
	study_Score = score;
}

void Score::set_daily_Score(double score)
{
	daily_Score = score;
}

void Score::set_per_Score(double score)
{
	per_Score = score;
}

void Score::set_inter_Score(double score)
{
	inter_Score = score;
}
