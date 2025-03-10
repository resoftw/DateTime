#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <optional>
namespace Datime {
#define CEI constexpr inline	
#define CE constexpr

	enum class Hari {
		Ahad, Senin, Selasa, Rabu, Kamis, Jumat, Sabtu,
	};
	enum class Bulan {
		January = 1, Februari, Maret, April, Mei, Juni,
		Juli, Agustus, September, Oktober, November, Desember,
	};

	class tahun {
		short t_;
	public:
		tahun() = default;
		CEI tahun(int y) noexcept : t_(static_cast<decltype(t_)>(y)) {}
		CEI tahun& operator++() noexcept { ++t_; return *this; }
		CEI tahun operator++(int) noexcept { auto tmp(*this); ++(*this); return tmp; }
		CEI tahun& operator--() noexcept { --t_; return *this; }
		CEI tahun operator--(int) noexcept { auto tmp(*this); --(*this); return tmp; }
		CEI tahun& operator+=(const tahun& t) noexcept { *this = *this + t; return *this; }
		CEI tahun& operator-=(const tahun& t) noexcept { *this = *this - t; return *this; }

		CEI tahun operator-() const noexcept { return tahun{ -t_ }; }
		CEI operator int() const noexcept { return t_; }

		CEI bool kabisat() const noexcept {
			return t_ % 4 == 0 && (t_ % 100 != 0 || t_ % 400 == 0);
		}
	};
	CE tahun operator+(const tahun& x, const tahun& y) noexcept { return tahun{ static_cast<int>(x) + static_cast<int>(y) }; }
	CE tahun operator-(const tahun& x, const tahun& y) noexcept { return tahun{ static_cast<int>(x) - static_cast<int>(y) }; }

	class bulan {
		int b_;
	public:
		bulan() = default;
		CEI bulan(int b) noexcept :b_(static_cast<decltype(b_)>(b)) {}
		CEI bulan(Bulan b) noexcept :b_(static_cast<decltype(b_)>(b)) {}
		CEI bulan& operator++() noexcept { *this += bulan{ 1 }; return *this; }
		CEI bulan operator++(int) noexcept { auto tmp(*this); ++(*this); return tmp; }
		CEI bulan& operator--() noexcept { *this -= bulan{ 1 }; return *this; }
		CEI bulan operator--(int) noexcept { auto tmp(*this); --(*this); return tmp; }
		CEI bulan& operator+=(const bulan& b) noexcept { *this = *this + b; return *this; }
		CEI bulan& operator-=(const bulan& b) noexcept { *this = *this - b; return *this; }

		CEI bulan operator-() const noexcept { return bulan{ -b_ }; }
		CEI operator int() const noexcept { return b_; }
	};

	CE bulan operator+(const bulan& x, const bulan& y) noexcept { return bulan{ static_cast<int>(x) + static_cast<int>(y) }; }
	CE bulan operator-(const bulan& x, const bulan& y) noexcept { return bulan{ static_cast<int>(x) - static_cast<int>(y) }; }

	class hari {
		int h_;
	public:
		hari() = default;
		CEI hari(int h) noexcept :h_(static_cast<decltype(h_)>(h)) {}
		CEI hari& operator++() noexcept { *this += hari{ 1 }; return *this; }
		CEI hari operator++(int) noexcept { auto tmp(*this); ++(*this); return tmp; }
		CEI hari& operator--() noexcept { *this -= hari{ 1 }; return *this; }
		CEI hari operator--(int) noexcept { auto tmp(*this); --(*this); return tmp; }
		CEI hari& operator+=(const hari& h) noexcept { *this = *this + h; return *this; }
		CEI hari& operator-=(const hari& h) noexcept { *this = *this - h; return *this; }

		CEI hari operator-() const noexcept { return hari{ -h_ }; }
		CEI operator int() const noexcept { return h_; }
	};
	CE hari operator+(const hari& x, const hari& y) noexcept { return hari{ static_cast<int>(x) + static_cast<int>(y) }; }
	CE hari operator-(const hari& x, const hari& y) noexcept { return hari{ static_cast<int>(x) - static_cast<int>(y) }; }

	class jam {
		int j_;
	public:
		jam() = default;
		CEI jam(int j) noexcept :j_(static_cast<decltype(j_)>(j)) {}
		CEI jam& operator++() noexcept { *this += jam{ 1 }; return *this; }
		CEI jam operator++(int) noexcept { auto tmp(*this); ++(*this); return tmp; }
		CEI jam& operator--() noexcept { *this -= jam{ 1 }; return *this; }
		CEI jam operator--(int) noexcept { auto tmp(*this); --(*this); return tmp; }
		CEI jam& operator+=(const jam& j) noexcept { *this = *this + j; return *this; }
		CEI jam& operator-=(const jam& j) noexcept { *this = *this - j; return *this; }

		CEI jam operator-() const noexcept { return jam{ -j_ }; }
		CEI operator int() const noexcept { return j_; }
	};
	CE jam operator+(const jam& x, const jam& y) noexcept { return jam{ static_cast<int>(x) + static_cast<int>(y) }; }
	CE jam operator-(const jam& x, const jam& y) noexcept { return jam{ static_cast<int>(x) - static_cast<int>(y) }; }

	class menit {
		int m_;
	public:
		menit() = default;
		CEI menit(int m) noexcept :m_(static_cast<decltype(m_)>(m)) {}
		CEI menit& operator++() noexcept { *this += menit{ 1 }; return *this; }
		CEI menit operator++(int) noexcept { auto tmp(*this); ++(*this); return tmp; }
		CEI menit& operator--() noexcept { *this -= menit{ 1 }; return *this; }
		CEI menit operator--(int) noexcept { auto tmp(*this); --(*this); return tmp; }
		CEI menit& operator+=(const menit& m) noexcept { *this = *this + m; return *this; }
		CEI menit& operator-=(const menit& m) noexcept { *this = *this - m; return *this; }
		CEI menit operator-() const noexcept { return menit{ -m_ }; }
		CEI operator int() const noexcept { return m_; }
	};
	CE menit operator+(const menit& x, const menit& y) noexcept { return menit{ static_cast<int>(x) + static_cast<int>(y) }; }
	CE menit operator-(const menit& x, const menit& y) noexcept { return menit{ static_cast<int>(x) - static_cast<int>(y) }; }

	class detik {
		int d_;
	public:
		detik() = default;
		CEI detik(int d) noexcept :d_(static_cast<decltype(d_)>(d)) {}
		CEI detik& operator++() noexcept { *this += detik{ 1 }; return *this; }
		CEI detik operator++(int) noexcept { auto tmp(*this); ++(*this); return tmp; }
		CEI detik& operator--() noexcept { *this -= detik{ 1 }; return *this; }
		CEI detik operator--(int) noexcept { auto tmp(*this); --(*this); return tmp; }
		CEI detik& operator+=(const detik& d) noexcept { *this = *this + d; return *this; }
		CEI detik& operator-=(const detik& d) noexcept { *this = *this - d; return *this; }
		CEI detik operator-() const noexcept { return detik{ -d_ }; }
		CEI operator int() const noexcept { return d_; }
	};
	CE detik operator+(const detik& x, const detik& y) noexcept { return detik{ static_cast<int>(x) + static_cast<int>(y) }; }
	CE detik operator-(const detik& x, const detik& y) noexcept { return detik{ static_cast<int>(x) - static_cast<int>(y) }; }

	class tanggal {
		tahun y_;
		bulan m_;
		hari d_;
	public:
		tanggal() = default;
		CEI tanggal(const tahun& y, const bulan& m, const hari& d) noexcept
			: y_(y), m_(m), d_(d) {
		}
		CEI tanggal(const int& y, const int& m, const int& d) noexcept
			: y_(y), m_(m), d_(d) {
		}
		CEI tanggal(const int& y, const Bulan& m, const int& d) noexcept
			: y_(y), m_(m), d_(d) {
		}

		CEI tanggal& operator+=(const hari& n)noexcept {
			int nd = int(d_) + int(n);
			int nm = dom();
			while (nd > nm) {
				nd -= nm;
				++m_;
				if (m_ == 13) {
					++y_;
					m_ = 1;
				}
				nm = dom();
			}
			while (nd < 1) {
				--m_;
				if (m_ == 0) {
					--y_;
					m_ = 12;
				}
				nd += dom();
			}
			d_ = nd;
			return *this;
		}
		CEI tanggal& operator-=(const hari& n)noexcept {
			*this += -n;
			return *this;
		}

		CEI tanggal& operator+=(const bulan& n)noexcept {
			int nm = int(m_) + int(n);
			while (nm > 12) {
				nm -= 12;
				++y_;
			}
			while (nm < 1) {
				nm += 12;
				--y_;
			}
			m_ = nm;
			if (d_ > dom()) {
				d_ = dom();
			}
			return *this;
		}
		CEI tanggal& operator-=(const bulan& n)noexcept {
			*this += -n;
			return *this;
		}

		CEI tanggal& operator+=(const tahun& n)noexcept {
			y_ += n;
			if (d_ > dom()) {
				d_ = dom();
			}
			return *this;
		}
		CEI tanggal& operator-=(const tahun& n)noexcept {
			*this += -n;
			return *this;
		}

		CEI tanggal& operator+=(const tanggal& n)noexcept {
			*this += n.y_;
			*this += n.m_;
			*this += n.d_;
			return *this;
		}
		CEI tanggal& operator-= (const tanggal& n)noexcept {
			*this -= n.y_;
			*this -= n.m_;
			*this -= n.d_;
			return *this;
		}


		CEI int dom(int y, int m) const noexcept {
			constexpr int dpm[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			Datime::tahun _y{ y };
			Datime::bulan _m{ m };
			return (_m == 2 && _y.kabisat()) ? 29 : dpm[int(_m) - 1];
		}
		CEI int dom() const noexcept {
			return dom(y_, m_);
		}

		CEI Datime::tahun tahun() const noexcept { return y_; }
		CEI Datime::bulan bulan() const noexcept { return m_; }
		CEI Datime::hari hari() const noexcept { return d_; }

		static std::optional<tanggal> from_string(const std::string& tms) noexcept {
			std::tm t = {};
			std::istringstream ss{ tms };
			ss >> std::get_time(&t, "%Y-%m-%d");
			if (ss.fail())return std::nullopt;
			return tanggal{ t.tm_year + 1900,t.tm_mon + 1,t.tm_mday };
		}


		inline std::string to_string() const noexcept {
			std::ostringstream os;
			os << y_ << "-"
				<< std::setfill('0') << std::setw(2) << m_ << "-"
				<< std::setfill('0') << std::setw(2) << d_;
			return os.str();
		}

		friend std::ostream& operator<<(std::ostream& os, const tanggal& d) {
			os << d.y_ << "-"
				<< std::setfill('0') << std::setw(2) << d.m_ << "-"
				<< std::setfill('0') << std::setw(2) << d.d_;
			return os;
		}
	};
	class waktu {
		int secs;
	public:
		waktu() = default;
		CEI waktu(int s) noexcept :secs(s) {}
		CEI waktu(jam h, menit m, detik s) noexcept :secs(h * 3600 + m * 60 + int(s)) {}
		CEI waktu(jam h) noexcept :secs(h * 3600) {}
		CEI waktu(menit m) noexcept :secs(m * 60) {}
		CEI waktu(detik s) noexcept :secs(int(s)) {}
		CEI waktu& operator+=(const detik& n)noexcept {
			secs += int(n);
			return *this;
		}
		CEI waktu& operator-=(const detik& n)noexcept {
			secs -= int(n);
			return *this;
		}
		CEI waktu& operator+=(const menit& n)noexcept {
			secs += int(n) * 60;
			return *this;
		}
		CEI waktu& operator-=(const menit& n)noexcept {
			secs -= int(n) * 60;
			return *this;
		}
		CEI waktu& operator+=(const jam& n)noexcept {
			secs += int(n) * 3600;
			return *this;
		}
		CEI waktu& operator-=(const jam& n)noexcept {
			secs -= int(n) * 3600;
			return *this;
		}

		CEI int tik() const noexcept { return secs; }
		CEI int detik() const noexcept { return secs % 60; }
		CEI int menit() const noexcept { return (secs % 3600) / 60; }
		CEI int jam() const noexcept { return secs / 3600; }

		inline std::string to_string() const noexcept {
			std::ostringstream os;
			int h = secs / 3600;
			int m = (secs % 3600) / 60;
			int s = secs % 60;
			os << std::setfill('0') << std::setw(2) << h << ":"
				<< std::setfill('0') << std::setw(2) << m << ":"
				<< std::setfill('0') << std::setw(2) << s;
			return os.str();
		}


		friend std::ostream& operator<<(std::ostream& os, const waktu& w) {
			int h = w.secs / 3600;
			int m = (w.secs % 3600) / 60;
			int s = w.secs % 60;
			os << std::setfill('0') << std::setw(2) << h << ":"
				<< std::setfill('0') << std::setw(2) << m << ":"
				<< std::setfill('0') << std::setw(2) << s;
			return os;
		}
	};
	CEI bool operator==(const tanggal& x, const tanggal& y) noexcept {
		return x.tahun() == y.tahun() && x.bulan() == y.bulan() && x.hari() == y.hari();
	}
	CEI bool operator!=(const tanggal& x, const tanggal& y) noexcept {
		return !(x == y);
	}
	CEI bool operator<(const tanggal& x, const tanggal& y) noexcept {
		if (x.tahun() < y.tahun()) return true;
		if (x.tahun() > y.tahun()) return false;
		if (x.bulan() < y.bulan()) return true;
		if (x.bulan() > y.bulan()) return false;
		return x.hari() < y.hari();
	}
	CEI bool operator>(const tanggal& x, const tanggal& y) noexcept {
		return y < x;
	}
	CEI bool operator<=(const tanggal& x, const tanggal& y) noexcept {
		return !(y < x);
	}
	CEI bool operator>=(const tanggal& x, const tanggal& y) noexcept {
		return !(x < y);
	}
	CEI tanggal operator+(const tanggal& x, const hari& y) noexcept {
		tanggal tmp = x;
		tmp += y;
		return tmp;
	}
	CEI tanggal operator-(const tanggal& x, const hari& y) noexcept {
		tanggal tmp = x;
		tmp -= y;
		return tmp;
	}
	CEI hari operator-(const tanggal& x, const tanggal& y) noexcept {
		int nd = int(x.hari()) + x.dom() * (int(x.bulan()) - 1) + x.dom() * 12 * (int(x.tahun()) - 1);
		int md = int(y.hari()) + y.dom() * (int(y.bulan()) - 1) + y.dom() * 12 * (int(y.tahun()) - 1);
		return hari{ nd - md };
	}
	CEI tanggal operator+(const tanggal& x, const bulan& y) noexcept {
		tanggal tmp = x;
		tmp += y;
		return tmp;
	}
	CEI tanggal operator-(const tanggal& x, const bulan& y) noexcept {
		tanggal tmp = x;
		tmp -= y;
		return tmp;
	}
	CEI bool operator==(const waktu& x, const waktu& y) noexcept {
		return x.tik() == y.tik();
	}
	CEI bool operator!=(const waktu& x, const waktu& y) noexcept {
		return !(x == y);
	}

	CEI waktu operator+(const waktu& x, const detik& y) noexcept {
		waktu tmp = x;
		tmp += y;
		return tmp;
	}
	CEI waktu operator-(const waktu& x, const detik& y) noexcept {
		waktu tmp = x;
		tmp -= y;
		return tmp;
	}
	CEI waktu operator+(const waktu& x, const menit& y) noexcept {
		waktu tmp = x;
		tmp += y;
		return tmp;
	}
	CEI waktu operator-(const waktu& x, const menit& y) noexcept {
		waktu tmp = x;
		tmp -= y;
		return tmp;
	}
	CEI waktu operator+(const waktu& x, const jam& y) noexcept {
		waktu tmp = x;
		tmp += y;
		return tmp;
	}
	CEI waktu operator-(const waktu& x, const jam& y) noexcept {
		waktu tmp = x;
		tmp -= y;
		return tmp;
	}
	CEI waktu operator+(const jam& x, const waktu& y) noexcept {
		return y + x;
	}
	CEI waktu operator-(const jam& x, const waktu& y) noexcept {
		return x - y;
	}
	CEI waktu operator+(const menit& x, const waktu& y) noexcept {
		return y + x;
	}
	CEI waktu operator-(const menit& x, const waktu& y) noexcept {
		return x - y;
	}
	CEI waktu operator+(const detik& x, const waktu& y) noexcept {
		return y + x;
	}
	CEI waktu operator-(const detik& x, const waktu& y) noexcept {
		return x - y;
	}
	CEI waktu operator+(const waktu& x, const waktu& y) noexcept {
		return waktu{ x.tik() + y.tik() };
	}
	CEI waktu operator-(const waktu& x, const waktu& y) noexcept {
		return waktu{ x.tik() - y.tik() };
	}
	CEI bool operator>(const waktu& x, const waktu& y) noexcept {
		return x.tik() > y.tik();
	}
	CEI bool operator<(const waktu& x, const waktu& y) noexcept {
		return x.tik() < y.tik();
	}
	CEI bool operator>=(const waktu& x, const waktu& y) noexcept {
		return x.tik() >= y.tik();
	}
	CEI bool operator<=(const waktu& x, const waktu& y) noexcept {
		return x.tik() <= y.tik();
	}

	class tanggalwaktu {
		tanggal tgl;
		waktu wkt;
	public:
		tanggalwaktu() = default;
		CEI tanggalwaktu(const tanggal& t) noexcept :tgl(t), wkt{ 0 } {}
		CEI tanggalwaktu(const tanggal& t, const waktu& w) noexcept :tgl(t), wkt(w) {}
		CEI tanggalwaktu(const int& y, const int& m, const int& d = 1, const int& h = 0, const int& mm = 0, const int& s = 0) noexcept
			:tgl{ y,m,d }, wkt{ h,mm,s } {
		}
		CEI tanggalwaktu& operator+=(const tanggal& n)noexcept {
			tgl += n;
			return *this;
		}
		CEI tanggalwaktu& operator+=(const hari& n)noexcept {
			tgl += n;
			return *this;
		}
		CEI tanggalwaktu& operator-=(const hari& n)noexcept {
			tgl -= n;
			return *this;
		}
		CEI tanggalwaktu& operator+=(const bulan& n)noexcept {
			tgl += n;
			return *this;
		}
		CEI tanggalwaktu& operator-=(const bulan& n)noexcept {
			tgl -= n;
			return *this;
		}
		CEI tanggalwaktu& operator+=(const tahun& n)noexcept {
			tgl += n;
			return *this;
		}
		CEI tanggalwaktu& operator-=(const tahun& n)noexcept {
			tgl -= n;
			return *this;
		}
		CEI tanggalwaktu& operator+=(const detik& n)noexcept {
			wkt += n;
			while (wkt.tik() >= 86400) {
				wkt -= detik{ 86400 };
				tgl += hari{ 1 };
			}
			while (wkt.tik() < 0) {
				wkt += detik{ 86400 };
				tgl -= hari{ 1 };
			}
			return *this;
		}
		CEI tanggalwaktu& operator-=(const detik& n)noexcept {
			return *this += -n;
		}
		CEI tanggalwaktu& operator+=(const menit& n)noexcept {
			wkt += n;
			while (wkt.tik() >= 86400) {
				wkt -= detik{ 86400 };
				tgl += hari{ 1 };
			}
			while (wkt.tik() < 0) {
				wkt += detik{ 86400 };
				tgl -= hari{ 1 };
			}
			return *this;
		}
		CEI tanggalwaktu& operator-=(const menit& n)noexcept {
			return *this += -n;
		}
		CEI tanggalwaktu& operator+=(const jam& n)noexcept {
			wkt += n;
			while (wkt.tik() >= 86400) {
				wkt -= detik{ 86400 };
				tgl += hari{ 1 };
			}
			while (wkt.tik() < 0) {
				wkt += detik{ 86400 };
				tgl -= hari{ 1 };
			}
			return *this;
		}
		CEI tanggalwaktu& operator-=(const jam& n)noexcept {
			return *this += -n;
		}
		CEI tanggalwaktu& operator+=(const waktu& n)noexcept {
			tgl += hari{ n.tik() / 86400 };
			wkt += detik{ n.tik() % 86400 };
			return *this;
		}
		CEI tanggalwaktu& operator-=(const waktu& n)noexcept {
			tgl -= hari{ n.tik() / 86400 };
			wkt -= detik{ n.tik() % 86400 };
			return *this;
		}
		CEI Datime::tanggal tanggal() const noexcept { return tgl; }
		CEI Datime::waktu waktu() const noexcept { return wkt; }
		inline std::string to_string() const noexcept {
			std::ostringstream os;
			os << tgl << " " << wkt;
			return os.str();
		}
		inline std::string to_utc() const noexcept {
			std::ostringstream os;
			os << tgl << "T" << wkt << "Z";
			return os.str();
		}
		//STATICS
		static std::optional<tanggalwaktu> from_string(const std::string& tms) noexcept {
			std::tm t = {};
			std::istringstream ss{ tms };
			ss >> std::get_time(&t, "%Y-%m-%d %H:%M:%S");
			if (ss.fail())return std::nullopt;
			return tanggalwaktu{ t.tm_year + 1900,t.tm_mon + 1,t.tm_mday,t.tm_hour,t.tm_min,t.tm_sec };
		}
		static std::optional<tanggalwaktu> from_utc_string(const std::string& tms) noexcept {
			std::tm t = {};
			std::istringstream ss{ tms };
			ss >> std::get_time(&t, "%Y-%m-%dT%H:%M:%SZ");
			if (ss.fail())return std::nullopt;
			return tanggalwaktu{ t.tm_year + 1900,t.tm_mon + 1,t.tm_mday,t.tm_hour,t.tm_min,t.tm_sec };
		}
		static tanggalwaktu from_sys_time(const std::chrono::system_clock::time_point& tp) {
			std::time_t t = std::chrono::system_clock::to_time_t(tp);
			std::tm tm;
			localtime_s(&tm, &t); // Konversi ke UTC
			return tanggalwaktu{ tm.tm_year + 1900,tm.tm_mon + 1,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec };
		}
		static tanggalwaktu from_sys_time_utc(const std::chrono::system_clock::time_point& tp) {
			std::time_t t = std::chrono::system_clock::to_time_t(tp);
			std::tm tm_utc;
			gmtime_s(&tm_utc, &t); // Konversi ke UTC
			return tanggalwaktu{ tm_utc.tm_year + 1900,tm_utc.tm_mon + 1,tm_utc.tm_mday,tm_utc.tm_hour,tm_utc.tm_min,tm_utc.tm_sec };
		}
		//FRIENDS
		friend std::ostream& operator<<(std::ostream& os, const tanggalwaktu& tw) {
			os << tw.tgl << " " << tw.wkt;
			return os;
		}
	};
	CEI bool operator==(const tanggalwaktu& x, const tanggalwaktu& y) noexcept {
		return x.tanggal() == y.tanggal() && x.waktu() == y.waktu();
	}
	CEI bool operator!=(const tanggalwaktu& x, const tanggalwaktu& y) noexcept {
		return !(x == y);
	}
	CEI bool operator<(const tanggalwaktu& x, const tanggalwaktu& y) noexcept {
		if (x.tanggal() < y.tanggal()) return true;
		if (x.tanggal() > y.tanggal()) return false;
		return x.waktu() < y.waktu();
	}
	CEI bool operator>(const tanggalwaktu& x, const tanggalwaktu& y) noexcept {
		return y < x;
	}
	CEI bool operator<=(const tanggalwaktu& x, const tanggalwaktu& y) noexcept {
		return !(y < x);
	}
	CEI bool operator>=(const tanggalwaktu& x, const tanggalwaktu& y) noexcept {
		return !(x < y);
	}
	CEI tanggalwaktu operator+(const tanggalwaktu& x, const hari& y) noexcept {
		tanggalwaktu tmp = x;
		tmp += y;
		return tmp;
	}
	CEI tanggalwaktu operator-(const tanggalwaktu& x, const hari& y) noexcept {
		tanggalwaktu tmp = x;
		tmp -= y;
		return tmp;
	}
	CEI tanggalwaktu operator+(const tanggalwaktu& x, const bulan& y) noexcept {
		tanggalwaktu tmp = x;
		tmp += y;
		return tmp;
	}
	CEI tanggalwaktu operator-(const tanggalwaktu& x, const bulan& y) noexcept {
		tanggalwaktu tmp = x;
		tmp -= y;
		return tmp;
	}
	CEI tanggalwaktu operator+(const tanggalwaktu& x, const tahun& y) noexcept {
		tanggalwaktu tmp = x;
		tmp += y;
		return tmp;
	}
	CEI tanggalwaktu operator-(const tanggalwaktu& x, const tahun& y) noexcept {
		tanggalwaktu tmp = x;
		tmp -= y;
		return tmp;
	}
	CEI tanggalwaktu operator+(const tanggalwaktu& x, const detik& y) noexcept {
		tanggalwaktu tmp = x;
		tmp += y;
		return tmp;
	}
	CEI tanggalwaktu operator-(const tanggalwaktu& x, const detik& y) noexcept {
		tanggalwaktu tmp = x;
		tmp -= y;
		return tmp;
	}
	CEI tanggalwaktu operator+(const tanggalwaktu& x, const menit& y) noexcept {
		tanggalwaktu tmp = x;
		tmp += y;
		return tmp;
	}
	CEI tanggalwaktu operator-(const tanggalwaktu& x, const menit& y) noexcept {
		tanggalwaktu tmp = x;
		tmp -= y;
		return tmp;
	}
	CEI tanggalwaktu operator+(const tanggalwaktu& x, const jam& y) noexcept {
		tanggalwaktu tmp = x;
		tmp += y;
		return tmp;
	}
	CEI tanggalwaktu operator-(const tanggalwaktu& x, const jam& y) noexcept {
		tanggalwaktu tmp = x;
		tmp -= y;
		return tmp;
	}
	CEI tanggalwaktu operator+(const tanggalwaktu& x, const waktu& y) noexcept {
		tanggalwaktu tmp = x;
		tmp += y;
		return tmp;
	}
	CEI tanggalwaktu operator-(const tanggalwaktu& x, const waktu& y) noexcept {
		tanggalwaktu tmp = x;
		tmp -= y;
		return tmp;
	}
}

