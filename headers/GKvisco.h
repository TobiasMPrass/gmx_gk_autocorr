#ifndef GKVISCO_H
#define GKVISCO_H

#include <Readfile.h>
#include <fftw3.h>

class GKvisco
{
  private:
    //member variables
    std::vector<std::vector<double>> m_offdiagoriginal, m_alloffdiagint, m_fftw_data;
    std::vector<std::vector<double>> m_sym, m_allint;
    std::vector<double>              m_temperature, m_time;
    double                           m_volume;

    double m_volavg, m_tempavg, m_timestep;

    //member functions
    void m_averagevolume();
    void m_averagetemperature();

    double* m_convert_v2a(std::vector<double>);

    void m_transpose_symmetrized(std::vector<std::vector<double>>);
    void m_transpose_integral();
    void m_symmetrize();
    void m_integrate(int);
    void m_viscosity();

    void m_do_compl_multpl(int N, fftw_complex *in, fftw_complex *out);

    void m_do_wk(int, fftw_complex*);

  public:
    //constructor
    GKvisco(std::unique_ptr<Readfile> const &ptrReadfile);


    //functions
    void calcvisco();
};

#endif
