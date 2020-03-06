#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

enum drm_sched_priority {
        DRM_SCHED_PRIORITY_MIN,
        DRM_SCHED_PRIORITY_NORMAL,
        DRM_SCHED_PRIORITY_HIGH_SW,
        DRM_SCHED_PRIORITY_HIGH_HW,
        DRM_SCHED_PRIORITY_KERNEL,
        DRM_SCHED_PRIORITY_MAX,
};

enum gfx_pipe_priority {
	AMDGPU_GFX_PIPE_PRIO_UNDEFINED,
	AMDGPU_GFX_PIPE_PRIO_NORMAL,
	AMDGPU_GFX_PIPE_PRIO_HIGH,

	AMDGPU_GFX_PIPE_PRIO_SIZE,
};

const enum gfx_pipe_priority s2p_prio_map[] = {
	[DRM_SCHED_PRIORITY_MIN] = AMDGPU_GFX_PIPE_PRIO_NORMAL,
	[DRM_SCHED_PRIORITY_NORMAL] = AMDGPU_GFX_PIPE_PRIO_NORMAL,
	[DRM_SCHED_PRIORITY_HIGH_SW] = AMDGPU_GFX_PIPE_PRIO_NORMAL,
	[DRM_SCHED_PRIORITY_HIGH_HW] = AMDGPU_GFX_PIPE_PRIO_HIGH,
	[DRM_SCHED_PRIORITY_KERNEL] = AMDGPU_GFX_PIPE_PRIO_HIGH,
};

/*
int static_map(int param)
{
	return s2p_prio_map[param];
}
*/

int with_switch(int param)
{
	switch (param) {
	case DRM_SCHED_PRIORITY_HIGH_HW:
	case DRM_SCHED_PRIORITY_KERNEL:
		return AMDGPU_GFX_PIPE_PRIO_HIGH;
	default:
		return AMDGPU_GFX_PIPE_PRIO_NORMAL;
	}
}

int test_perf_by_sz(int test_size)
{
	int test_data[test_size];
	int store_data[test_size];
	struct timeval  tv1, tv2;
	int i;

	printf("TESTING data size %d\n", test_size);
	/* generate data randomly */
	for (i = 0; i < test_size; i++)
		test_data[i] = rand() % 5;

	/* map */
	gettimeofday(&tv1, NULL);
	for (i = 0; i < test_size; i++)
		store_data[i] = s2p_prio_map[test_data[i]];

	gettimeofday(&tv2, NULL);
	printf ("%f sec, total time taken by static map conversion\n",
			(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
			(double) (tv2.tv_sec - tv1.tv_sec));

	/* switch */
	gettimeofday(&tv1, NULL);
	for (i = 0; i < test_size; i++)
		store_data[i] = with_switch(test_data[i]);

	gettimeofday(&tv2, NULL);

	printf ("%f sec, total time taken by switch conversion\n",
		(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
		(double) (tv2.tv_sec - tv1.tv_sec));

	return test_data[rand()%test_size];

}

void main(void)
{
	test_perf_by_sz(100000);
	test_perf_by_sz(100000);
	test_perf_by_sz(1000000);

}
