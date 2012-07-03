#ifndef FROMMOVIEPICKUPPER_H
#define FROMMOVIEPICKUPPER_H
#include "Pickupper.h"
#include "MovieLoader.h"
#include "MmmRoutine.h"
#include <fstream>

namespace fmv{

class FromMoviePickupper
{
    //FromMoviePickupper(){}
public:

    FromMoviePickupper(unsigned int mask_number)
        :pickupper(mask_number)
    {
    }

    void Load(const std::string& file_name)
    {
        this->movie_loader.Load(file_name);
        auto image_size = cvGetSize(this->movie_loader.GetFrame(0));
        this->pickupper.SetImageSize(image_size);

    }

    int GetMovieLength()
    {
        return this->movie_loader.GetMovieLength();
    }

    IplImage* GetMaskedFrame(int frame_number)
    {
        auto image = this->movie_loader.GetFrame(frame_number);
        auto masked = this->pickupper.Pickup(image);
        return masked;
    }

    IplImage* GetFrame(int frame_number)
    {
        auto image = this->movie_loader.GetFrame(frame_number);
        return image;
    }

    void SetMaskThresholdLower(unsigned int mask_creator_index, unsigned int color_index, char value)
    {
        this->pickupper.SetMaskThresholdLower(mask_creator_index, color_index, value);
    }

    void SetMaskThresholdHigher(unsigned int mask_creator_index, unsigned int color_index, char value)
    {
        this->pickupper.SetMaskThresholdHigher(mask_creator_index, color_index, value);
    }

    void ExportMaskedMovie(const std::string& file_name)
    {
        //auto codec = CV_FOURCC('M','J','P','G');//this->movie_loader.GetMovieCodec();
        auto fps = this->movie_loader.GetMovieFps();
        std::cout << "fps:" << fps << std::endl;
        auto frame_size = this->movie_loader.GetMovieSize();
        std::cout << "width:" << frame_size.width << std::endl;
        std::cout << "height:" << frame_size.height << std::endl;
        auto writer = cvCreateVideoWriter(file_name.c_str(), CV_FOURCC('M','J','P','G'), fps, frame_size);
        if(writer == NULL){std::cout << "ERROR!!" << std::endl;}
        auto movie_length = this->movie_loader.GetMovieLength();
        std::cout << "length:" << movie_length << std::endl;
        for(int i = 0; i < movie_length; i++)
        {
            std::cout << "=" << std::flush;
            IplImage* image = this->movie_loader.GetFrame(i);
            cvWriteFrame(writer, image);
        }
        std::cout << "ok" << std::flush;
        cvReleaseVideoWriter(&writer);
    }

    void ExportAsMmmFile(const std::string& file_name)
    {

        auto movie = mg::Color4bMovie();
        auto movie_length = this->movie_loader.GetMovieLength();
        for(int i = 0; i < movie_length; i++)
        {
            std::cout << "=" << std::flush;
            IplImage* image = this->GetMaskedFrame(i);
            auto mmm_image = mmm::ConvertIplImageToMmmImage(image);
            movie.AddFrame(mmm_image);
        }
        std::ofstream ofs(file_name.c_str());
        mg::SaveMovie(ofs, movie);
        std::cout << "ok" << std::flush;
    }
private:
    MovieLoader movie_loader;
    Pickupper pickupper;

};
}
#endif // FROMMOVIEPICKUPPER_H
