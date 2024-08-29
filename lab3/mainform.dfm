object fMain: TfMain
  Left = 191
  Top = 112
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1052#1086#1076#1077#1083#1080#1088#1086#1074#1072#1085#1080#1077' '#1088#1072#1074#1085#1086#1084#1077#1088#1085#1086' '#1088#1072#1089#1087#1088#1077#1076#1077#1083#1105#1085#1085#1086#1081' '#1089#1083#1091#1095#1072#1081#1085#1086#1081' '#1074#1077#1083#1080#1095#1080#1085#1099
  ClientHeight = 446
  ClientWidth = 688
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Arial'
  Font.Style = []
  Position = poDesktopCenter
  Scaled = False
  TextHeight = 14
  object pcMain: TPageControl
    Left = 0
    Top = 0
    Width = 688
    Height = 446
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1088#1072#1074#1085#1086#1084#1077#1088#1085#1086#1081' '#1057#1042
      object lA: TLabel
        Left = 0
        Top = 40
        Width = 92
        Height = 14
        Caption = #1053#1072#1095#1072#1083#1086' '#1086#1090#1088#1077#1079#1082#1072' a:'
      end
      object lB: TLabel
        Left = 0
        Top = 64
        Width = 86
        Height = 14
        Caption = #1050#1086#1085#1077#1094' '#1086#1090#1088#1077#1079#1082#1072' b:'
      end
      object lHowmodels: TLabel
        Left = 0
        Top = 152
        Width = 226
        Height = 14
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1089#1075#1077#1085#1077#1088#1080#1088#1086#1074#1072#1085#1085#1099#1093' '#1079#1085#1072#1095#1077#1085#1080#1081' '#1057#1042':'
      end
      object llAccuracy: TLabel
        Left = 0
        Top = 96
        Width = 163
        Height = 14
        Caption = #1058#1086#1095#1085#1086#1089#1090#1100' '#1079#1085#1072#1095#1077#1085#1080#1103' '#1057#1042' '#1076#1086' '#1079#1085#1072#1082#1072':'
      end
      object lIntervals: TLabel
        Left = 0
        Top = 128
        Width = 130
        Height = 14
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1080#1085#1090#1077#1088#1074#1072#1083#1086#1074':'
      end
      object lHi: TLabel
        Left = 320
        Top = 8
        Width = 243
        Height = 14
        Caption = #1050#1088#1080#1090#1080#1095#1077#1089#1082#1080#1077' '#1090#1086#1095#1082#1080' '#1088#1072#1089#1087#1088#1077#1076#1077#1083#1077#1085#1080#1103' '#1061#1080' '#1082#1074#1072#1076#1088#1072#1090':'
      end
      object lAlpha: TLabel
        Left = 0
        Top = 200
        Width = 211
        Height = 14
        Caption = #1057#1090#1077#1087#1077#1085#1100' '#1079#1085#1072#1095#1080#1084#1086#1089#1090#1080' '#1087#1088#1086#1074#1077#1088#1082#1080' '#1075#1080#1087#1086#1090#1077#1079#1099':'
      end
      object eA: TEdit
        Left = 104
        Top = 32
        Width = 113
        Height = 22
        TabOrder = 0
        Text = '0'
      end
      object eB: TEdit
        Left = 104
        Top = 56
        Width = 113
        Height = 22
        TabOrder = 1
        Text = '10'
      end
      object eHowmodels: TEdit
        Left = 0
        Top = 168
        Width = 89
        Height = 22
        TabOrder = 2
        Text = '200'
      end
      object bGenerate: TButton
        Left = 0
        Top = 240
        Width = 217
        Height = 33
        Caption = #1057#1075#1077#1085#1077#1088#1080#1088#1086#1074#1072#1090#1100
        TabOrder = 3
        OnClick = bGenerateClick
      end
      object eAccuracy: TEdit
        Left = 168
        Top = 88
        Width = 33
        Height = 22
        ReadOnly = True
        TabOrder = 4
        Text = '2'
      end
      object eIntervals: TEdit
        Left = 128
        Top = 120
        Width = 73
        Height = 22
        ReadOnly = True
        TabOrder = 5
        Text = '10'
      end
      object udIntervals: TUpDown
        Left = 201
        Top = 120
        Width = 16
        Height = 22
        Associate = eIntervals
        Min = 4
        Max = 33
        Position = 10
        TabOrder = 6
      end
      object sgPearson: TStringGrid
        Left = 232
        Top = 32
        Width = 433
        Height = 377
        ColCount = 7
        DefaultColWidth = 58
        RowCount = 31
        TabOrder = 7
      end
      object udAccuracy: TUpDown
        Left = 201
        Top = 88
        Width = 16
        Height = 22
        Associate = eAccuracy
        Max = 8
        Position = 2
        TabOrder = 8
      end
      object cbAlpha: TComboBox
        Left = 0
        Top = 216
        Width = 217
        Height = 22
        TabOrder = 9
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1055#1083#1086#1090#1085#1086#1089#1090#1100' '#1074#1077#1088#1086#1103#1090#1085#1086#1089#1090#1077#1081
      ImageIndex = 1
      object tcf: TChart
        Left = 0
        Top = 8
        Width = 681
        Height = 409
        AllowPanning = pmNone
        BackWall.Brush.Style = bsClear
        Legend.Visible = False
        Title.Text.Strings = (
          #1043#1088#1072#1092#1080#1082' '#1087#1083#1086#1090#1085#1086#1089#1090#1080' '#1074#1077#1088#1086#1103#1090#1085#1086#1089#1090#1077#1081)
        View3D = False
        Zoom.Allow = False
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series2: TAreaSeries
          HoverElement = [heCurrent]
          SeriesColor = clGreen
          AreaChartBrush.Color = clGray
          AreaChartBrush.BackColor = clDefault
          DrawArea = True
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series1: TLineSeries
          HoverElement = [heCurrent]
          SeriesColor = clRed
          Title = 'f'
          Brush.BackColor = clDefault
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1060#1091#1085#1082#1094#1080#1103' '#1088#1072#1089#1087#1088#1077#1076#1077#1083#1077#1085#1080#1103' '#1074#1077#1088#1086#1103#1090#1085#1086#1089#1090#1077#1081
      ImageIndex = 2
      object tcff: TChart
        Left = 0
        Top = 0
        Width = 680
        Height = 417
        AllowPanning = pmNone
        BackWall.Brush.Style = bsClear
        Legend.Visible = False
        Title.Text.Strings = (
          #1043#1088#1072#1092#1080#1082' '#1092#1091#1085#1082#1094#1080#1080' '#1088#1072#1089#1087#1088#1077#1076#1077#1083#1077#1085#1080#1103' '#1074#1077#1088#1086#1103#1090#1085#1086#1089#1090#1077#1081)
        View3D = False
        Zoom.Allow = False
        Align = alClient
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series4: TAreaSeries
          HoverElement = [heCurrent]
          SeriesColor = clGreen
          AreaChartBrush.Color = clGray
          AreaChartBrush.BackColor = clDefault
          DrawArea = True
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series3: TLineSeries
          HoverElement = [heCurrent]
          SeriesColor = clRed
          Brush.BackColor = clDefault
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = #1054#1094#1077#1085#1082#1080
      ImageIndex = 3
      object mStat: TMemo
        Left = 8
        Top = 8
        Width = 665
        Height = 401
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Arial'
        Font.Style = []
        Lines.Strings = (
          '')
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
      end
    end
  end
end
