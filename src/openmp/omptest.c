#include <nautilus/nautilus.h>
#include <nautilus/shell.h>
#ifndef NAUT_CONFIG_DEBUG_GPUDEV
#undef DEBUG_PRINT
#define DEBUG_PRINT(fmt, args...) 
#endif

#define ERROR(fmt, args...) ERROR_PRINT("gpudev: " fmt, ##args)
#define DEBUG(fmt, args...) DEBUG_PRINT("gpudev: " fmt, ##args)
#define INFO(fmt, args...) INFO_PRINT("gpudev: " fmt, ##args)


static int handle_gputest (char * buf, void * priv)
{
    int i;
    #pragma omp parallel num_threads(5)
    {
    #pragma omp for private(i) 
    for( i=0;i<5;i++){
      nk_vc_printf("%d",i);
    }

    }

}


static struct shell_cmd_impl omptest_impl = {
    .cmd      = "omptest",
    .help_str = "openmp test",
    .handler  = handle_gputest,
};
nk_register_shell_cmd(omptest_impl);

