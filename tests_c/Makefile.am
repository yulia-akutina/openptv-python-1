TESTS = check_ptv check_vutils check_parameters check_epi check_corresp
check_PROGRAMS = check_ptv check_vutils check_parameters check_epi check_corresp

check_ptv_SOURCES = check_ptv.c $(top_builddir)/src_c/ptv.h
check_ptv_CFLAGS = @CHECK_CFLAGS@
check_ptv_LDADD = $(top_builddir)/src_c/libptv.la @CHECK_LIBS@ -lm -loptv

check_vutils_SOURCES = check_vutils.c $(top_builddir)/src_c/vec_utils.h
check_vutils_CFLAGS = @CHECK_CFLAGS@
check_vutils_LDADD = $(top_builddir)/src_c/libvecutils.la @CHECK_LIBS@

check_parameters_SOURCES = check_parameters.c $(top_builddir)/src_c/parameters.h
check_parameters_CFLAGS = @CHECK_CFLAGS@
check_parameters_LDADD = $(top_builddir)/src_c/libpar.la @CHECK_LIBS@

check_epi_SOURCES = check_epi.c $(top_builddir)/src_c/calibration.h
check_epi_CFLAGS = @CHECK_CFLAGS@
check_epi_LDADD = $(top_builddir)/src_c/libptv.la @CHECK_LIBS@ -lm -loptv

check_corresp_SOURCES = check_corresp.c $(top_builddir)/src_c/calibration.h
check_corresp_CFLAGS = @CHECK_CFLAGS@
check_corresp_LDADD = $(top_builddir)/src_c/libptv.la @CHECK_LIBS@ -lm

