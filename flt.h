#ifndef FILTER_H
#define FILTER_H


class Filter
{
public:
        Filter(void);
        Filter(float H,float T);
        void	Ini(float H,float T);
        float	Go(float val);
        void	Reset(void);
        float	V, W, last, lastf;
        int	Enter, Ready;
private:

};

#endif // FILTER_H
