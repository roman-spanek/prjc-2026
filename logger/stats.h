#ifndef STATS_H
#define STATS_H

void stats_reset(void);
void stats_add(float value);
int stats_count(void);
float stats_min(void);
float stats_max(void);
float stats_average(void);

#endif