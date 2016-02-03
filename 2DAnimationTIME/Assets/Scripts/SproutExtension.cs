using UnityEngine;
using System;
using System.Collections;
using System.Drawing;
using System.Drawing.Imaging;
using hp.pc;

public static class SproutExtension
{
    public static Bitmap createBitmap(PcImage pcImage)
    {
        Bitmap bmp;

        switch (pcImage.PixelFormat)
        {
            case PcPixelFormat.BGR:
                bmp = new Bitmap(pcImage.Size.Width, pcImage.Size.Height, pcImage.RowSize, PixelFormat.Format24bppRgb, pcImage.BufferHandle);
                break;
            case PcPixelFormat.BGRA:
                bmp = new Bitmap(pcImage.Size.Width, pcImage.Size.Height, pcImage.RowSize, PixelFormat.Format32bppArgb, pcImage.BufferHandle);
                break;
            case PcPixelFormat.Grayscale:
                bmp = new Bitmap(pcImage.Size.Width, pcImage.Size.Height, pcImage.RowSize, PixelFormat.Format16bppGrayScale, pcImage.BufferHandle);
                break;
            case PcPixelFormat.Grayscale16:
                bmp = new Bitmap(pcImage.Size.Width, pcImage.Size.Height, pcImage.RowSize, PixelFormat.Format16bppGrayScale, pcImage.BufferHandle);
                break;
            default:
                bmp = new Bitmap(pcImage.Size.Width, pcImage.Size.Height, pcImage.RowSize, PixelFormat.DontCare, pcImage.BufferHandle);
                break;
        }

        return bmp;
    }

    public static Texture2D captureFrame()
    {
        const int DOWN_SAMPLE_RATE = 1;

        Texture2D frame;
        IPcLink link = HPPC.CreateLink();
        IPcMoment moment = link.CaptureMoment();
        IPcPicture picture = link.ExtractPicture(moment);
        Bitmap bmp = SproutExtension.createBitmap(picture.Image);

        GraphicsUnit units = GraphicsUnit.Pixel;
        RectangleF rect = bmp.GetBounds(ref units);
        int width = (int)rect.Width / DOWN_SAMPLE_RATE, height = (int)rect.Height / DOWN_SAMPLE_RATE;
        frame = new Texture2D(width, height);

        UnityEngine.Color[] colors = new UnityEngine.Color[width * height];

        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                System.Drawing.Color sysColor = bmp.GetPixel(x * DOWN_SAMPLE_RATE, y * DOWN_SAMPLE_RATE);
                UnityEngine.Color32 uc32 = new UnityEngine.Color32(sysColor.R, sysColor.B, sysColor.G, sysColor.A);
                //UnityEngine.Color unityColor = new UnityEngine.Color((float)sysColor.R / 255f, (float)sysColor.G / 255f, (float)sysColor.B / 255f, (float)sysColor.A / 255f);
                colors[(height - y) * width + x] = uc32;
            }
        }

        frame.SetPixels(colors);

        frame.Apply();

        TextureScale.Point(frame, 512, 512);

        return frame;
    }
}
