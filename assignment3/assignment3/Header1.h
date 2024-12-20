#ifndef MP3_COMMENT_HPP
#define MP3_COMMENT_HPP

#include <string>


char genre[148][32] = { "Blues", "Classic Rock", "Country", "Dance", "Disco", "Funk",
"Grunge", "Hip-Hop", "Jazz", "Metal", "New Age", "Oldies", "Other", "Pop", "R&B",
"Rap", "Reggae", "Rock", "Techno", "Industrial", "Alternative", "Ska", "Death Metal",
"Pranks", "Soundtrack", "Euro-Techno", "Ambient", "Trip-Hop", "Vocal", "Jazz+Funk",
"Fusion", "Trance", "Classical", "Instrumental", "Acid", "House", "Game", "Sound Clip",
"Gospel", "Noise", "Alternative Rock", "Bass", "Soul", "Punk", "Space", "Meditative",
"Instrumental Pop", "Instrumental Rock", "Ethnic", "Gothic", "Darkwave", "TechnoIndustrial", 
"Electronic", "Pop-Folk", "Eurodance", "Dream", "Southern Rock", "Comedy", "Cult", "Gangsta", 
"Top 40", "Christian Rap", "Pop/Funk", "Jungle", "Native American", "Cabaret", "New Wave", "Psychadelic", 
"Rave", "Showtunes", "Trailer", "LoFi", "Tribal", "Acid Punk", "Acid Jazz", "Polka", "Retro", "Musical", 
"Rock & Roll", "Hard Rock", "Folk", "Folk - Rock", "National Folk", "Swing", "Fast Fusion", "Bebob", "Latin",
"Revival", "Celtic", "Bluegrass", "Avantgarde", "Gothic Rock", "Progressive Rock",
"Psychedelic Rock", "Symphonic Rock", "Slow Rock", "Big Band", "Chorus",
"Easy Listening", "Acoustic", "Humour", "Speech", "Chanson", "Opera", "Chamber Music",
"Sonata", "Symphony", "Booty Bass", "Primus", "Porn Groove", "Satire", "Slow Jam",
"Club", "Tango", "Samba", "Folklore", "Ballad", "Power Ballad", "Rhythmic Soul",
"Freestyle", "Duet", "Punk Rock", "Drum Solo", "Acapella", "Euro-House", "Dance Hall",
"Goa", "Drum & Bass", "Club - House", "Hardcore", "Terror", "Indie", "BritPop",
"Negerpunk", "Polsk Pumk", "Beat", "Christian Gangsta Rap", "Heavy Metal", "Black Metal",
"Crossover", "Contemporary Christian", "Christian Rock", "Merengue", "Salsa",
"Thrash Metal", "Anime", "JPop", "Synthpop"
};


struct MP3 {
	char header[3];
	char songTitle[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[29];
	char trackNumber[1];
	char genre;
};

#endif 