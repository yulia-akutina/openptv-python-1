/* Unit/regression tests for code in src_c/epi.c */

#include <check.h>
#include <stdlib.h>
#include <unistd.h>

#include "../src_c/calibration.h"
#include "../src_c/parameters.h"
#include "../src_c/typedefs.h"

START_TEST(test_epi_mm)
{
    double xin, yin;
    double xmin, ymin, xmax, ymax;
    mm_np media_par = {1, 1., {1.49, 0., 0.}, {5., 0., 0.}, 1.33, 1.};
    volume_par *vpar;
    Calibration* cal[2];
    
    cal[0] = read_calibration("testing_fodder/cal/cam1.tif.ori",
        "testing_fodder/cal/cam1.tif.addpar", NULL);
    cal[1] = read_calibration("testing_fodder/cal/cam2.tif.ori",
        "testing_fodder/cal/cam2.tif.addpar", NULL);
    vpar = read_volume_par("testing_fodder/parameters/criteria.par");
    
    xin = 10.;
    yin = 10.;
    epi_mm(xin, yin,
        cal[0]->ext_par, cal[0]->int_par, cal[0]->glass_par,
        cal[1]->ext_par, cal[1]->int_par, cal[1]->glass_par,
        media_par, vpar, &xmin, &ymin, &xmax, &ymax);
    
    fail_unless((abs(xmin - (-9.209233)) < 1e-6) && (abs(ymin - 21.758034) < 1e-6) 
        && (abs(xmax - 10.067018) < 1e-6) && (abs(ymax - 20.877886) < 1e-6));
}
END_TEST

START_TEST(test_epi_mm_2D)
{
    double xin, yin;
    double xout, yout, zout;
    mm_np media_par = {1, 1., {1.49, 0., 0.}, {5., 0., 0.}, 1.33, 1.};
    volume_par *vpar;
    Calibration* cal;
    
    cal = read_calibration("testing_fodder/cal/cam1.tif.ori",
        "testing_fodder/cal/cam1.tif.addpar", NULL);
    vpar = read_volume_par("testing_fodder/parameters/criteria.par");
    
    xin = 10.;
    yin = 10.;
    epi_mm_2D(xin, yin, cal->ext_par, cal->int_par, cal->glass_par,
        media_par, vpar, &xout, &yout, &zout);
    
    printf("fail_unless((abs(xout - (%.6f)) < 1e-6) && (abs(yout - %.6f) < 1e-6)" 
        "&& (abs(zout - %.6f) < 1e-6));\n", xout, yout, zout);
    fail_unless((abs(xout - (49.985492)) < 1e-6) && 
        (abs(yout - 54.186109) < 1e-6) && (abs(zout - 0.000000) < 1e-6));
}
END_TEST

Suite* epi_suite(void) {
    Suite *s = suite_create ("Epipolar lines");

    TCase *tc = tcase_create ("Line window 3D");
    tcase_add_test(tc, test_epi_mm);
    suite_add_tcase (s, tc);

    tc = tcase_create ("Line window 2D");
    tcase_add_test(tc, test_epi_mm_2D);
    suite_add_tcase (s, tc);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s = epi_suite ();
    SRunner *sr = srunner_create (s);
    srunner_run_all (sr, CK_ENV);
    number_failed = srunner_ntests_failed (sr);
    srunner_free (sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
