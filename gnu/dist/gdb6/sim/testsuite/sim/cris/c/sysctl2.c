/* Check error message for invalid sysctl call.
#xerror:
#output: Unimplemented _sysctl syscall *\n
#output: program stopped with signal 4.\n
#notarget: cris*-*-elf
*/

#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  static int sysctl_args[] = { 99, 99 };
  size_t x = 8;

  struct __sysctl_args {
    int *name;
    int nlen;
    void *oldval;
    size_t *oldlenp;
    void *newval;
    size_t newlen;
    unsigned long __unused[4];
  } scargs
      =
   {
     sysctl_args,
     sizeof (sysctl_args) / sizeof (sysctl_args[0]),
     (void *) -1, &x, NULL, 0
   };

 syscall (SYS__sysctl, &scargs);
 printf ("xyzzy\n");
 exit (0);
}